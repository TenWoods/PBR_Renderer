#include "Model.h"
#include "Render.h"
#include "stb_image.h"
#include <iostream>

unsigned int TextureFromFile(const char* path, const std::string& directory, Render* window);

Model::Model(std::string const& path, Render* window) : RenderObject(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), window)
{
    LoadModel(path);
}

void Model::LoadModel(std::string const& path)
{
	Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString();
        return;
    }
    //保存模型上级目录
    directory = path.substr(0, path.find_last_of('/'));
    //处理每个节点
    ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
    //处理当前节点所有mesh
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(ProcessMesh(mesh, scene));
    }
    //递归处理所有子节点
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        ProcessNode(node->mChildren[i], scene);
    }
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;
        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.normal = vector;
        if (mesh->mTextureCoords[0])
        {
            glm::vec2 texcoord;
            texcoord.x = mesh->mTextureCoords[0][i].x;
            texcoord.y = mesh->mTextureCoords[0][i].y;
            vertex.texcoord = texcoord;
        }
        else
            vertex.texcoord = glm::vec2(0.0f, 0.0f);
        vector.x = mesh->mTangents[i].x;
        vector.y = mesh->mTangents[i].y;
        vector.z = mesh->mTangents[i].z;
        vertex.tangent = vector;
        vector.x = mesh->mBitangents[i].x;
        vector.y = mesh->mBitangents[i].y;
        vector.z = mesh->mBitangents[i].z;
        vertex.bitangent = vector;
        vertices.push_back(vertex);
    }
    //处理索引
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }
    //处理贴图
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
    //环境光贴图->ao
    std::vector<Texture> aoMaps = LoadTextures(material, aiTextureType_AMBIENT, TEXTURE_TYPE::AO);
    textures.insert(textures.end(), aoMaps.begin(), aoMaps.end());
    //漫反射贴图
    std::vector<Texture> diffuseMaps = LoadTextures(material, aiTextureType_DIFFUSE, TEXTURE_TYPE::DIFFUSE);
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    //高光贴图->粗糙度贴图
    std::vector<Texture> specularMaps = LoadTextures(material, aiTextureType_SPECULAR, TEXTURE_TYPE::ROUGHNESS);
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    //法线贴图
    std::vector<Texture> normalMaps = LoadTextures(material, aiTextureType_HEIGHT, TEXTURE_TYPE::NORMAL);
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    //高度贴图->金属度贴图
    std::vector<Texture> heightMaps = LoadTextures(material, aiTextureType_AMBIENT, TEXTURE_TYPE::METALLIC);
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
    return Mesh(vertices, indices, textures, m_window);
}

std::vector<Texture> Model::LoadTextures(aiMaterial* material, aiTextureType type, TEXTURE_TYPE typeName)
{
    std::vector<Texture> textures;
    for (unsigned int i = 0; i < material->GetTextureCount(type); i++)
    {
        aiString str;
        material->GetTexture(type, i, &str);
        bool skip = false;
        for (unsigned int j = 0; j < loaded_texture.size(); j++)
        {
            //判断是否已经加载过
            if (std::strcmp(loaded_texture[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(loaded_texture[j]);
                skip = true;
                break;
            }
        }
        if (!skip)
        {
            Texture texture;
            texture.id = TextureFromFile(str.C_Str(), this->directory, m_window);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            loaded_texture.push_back(texture);
        }
    }
    return textures;
}

unsigned int TextureFromFile(const char* path, const std::string& directory, Render* window)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    window->glGenTextures(1, &textureID);

    int width, height, channel;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channel, 0);
    if (data)
    {
        GLenum format = GL_RED;
        if (channel == 1)
            format = GL_RED;
        else if (channel == 3)
            format = GL_RGB;
        else if (channel == 4)
            format = GL_RGBA;
        window->glBindTexture(GL_TEXTURE_2D, textureID);
        window->glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        window->glGenerateMipmap(GL_TEXTURE_2D);

        window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        qDebug() << "Texture failed to load at path: " << path;
        stbi_image_free(data);
    }
    return textureID;
}

void Model::Draw(QOpenGLShaderProgram* shader)
{
    QMatrix4x4 model;
    shader->bind();
    model.translate(m_position);
    model.scale(m_scale);
    model.rotate(QQuaternion::fromEulerAngles(m_rotation));
    shader->setUniformValue("model", model);
    QMatrix4x4 view;
    view = m_window->camera.ViewMatrix();
    shader->setUniformValue("view", view);
    QMatrix4x4 projection;
    projection.perspective(m_window->camera.get_zoom(), (float)m_window->width() / (float)m_window->height(), 0.1f, 100.0f);
    shader->setUniformValue("projection", projection);
    shader->release();
    for (int i = 0; i < meshes.size(); i++)
    {
        meshes[i].Draw(shader);
    }
}