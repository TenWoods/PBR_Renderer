#include "Cube.h"
#include <qmath.h>
#include "Render.h"
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

Cube::Cube() : RenderObject(), VAO(0), VBO(0)
{

}

Cube::Cube(QVector3D position, QVector3D scale, QVector3D rotation, Render* window) : RenderObject(position, scale, rotation, window), hasInit(false)
{
    
}

void Cube::Draw(QOpenGLShaderProgram* shader)
{
    if (!hasInit)
    {
        float vertices[] = {
            // positions          // normals        //tagents            // texture coords
                -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,

                -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
                -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
                -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f,

                -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
                -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
                -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,

                0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

                -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
                0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
                0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
                -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,

                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
        };
        m_window->glGenVertexArrays(1, &VAO);
        m_window->glGenBuffers(1, &VBO);
        m_window->glBindVertexArray(VAO);
        m_window->glBindBuffer(GL_ARRAY_BUFFER, VBO);
        m_window->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        m_window->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GL_FLOAT), (void*)0);
        m_window->glEnableVertexAttribArray(0);
        m_window->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
        m_window->glEnableVertexAttribArray(1);
        m_window->glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
        m_window->glEnableVertexAttribArray(2);
        m_window->glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GL_FLOAT), (void*)(9 * sizeof(GL_FLOAT)));
        m_window->glEnableVertexAttribArray(3);
    }
    QMatrix4x4 model;
    shader->bind();
    int index = 3;
    for (unsigned int i = 0; i < m_textures.size(); i++)
    {
        switch (m_textures[i].type)
        {
        case TEXTURE_TYPE::DIFFUSE :
            shader->setUniformValue("material.texture_diffuse", index);
            break;
        case TEXTURE_TYPE::SPECULAR :
            shader->setUniformValue("material.texture_specular", index);
            break;
        case TEXTURE_TYPE::NORMAL :
            shader->setUniformValue("material.texture_normal", index);
            break;
        case TEXTURE_TYPE::HEIGHT :
            shader->setUniformValue("material.texture_height", index);
            break;
        case TEXTURE_TYPE::METALLIC :
            shader->setUniformValue("material.texture_metallic", index);
            break;
        case TEXTURE_TYPE::ROUGHNESS :
            shader->setUniformValue("material.texture_roughness", index);
            break;
        case TEXTURE_TYPE::AO :
            shader->setUniformValue("material.texture_ao", index);
            break;
        default :
            break;
        }
        m_window->glActiveTexture(GL_TEXTURE0 + index);
        m_window->glBindTexture(GL_TEXTURE_2D, m_textures[i].id);
        index++;
    }
    shader->setUniformValue("albedo", color);
    shader->setUniformValue("metallic", metallic);
    shader->setUniformValue("roughness", roughness);
    shader->setUniformValue("ao", ao);
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
    m_window->glBindVertexArray(VAO);
    m_window->glDrawArrays(GL_TRIANGLES, 0, 36);
    shader->release();
    m_window->glBindVertexArray(0);
    hasInit = true;
}

void Cube::AddTexture(std::string path, TEXTURE_TYPE type)
{
    unsigned int tex;
    m_window->glGenTextures(1, &tex);
    m_window->glBindTexture(GL_TEXTURE_2D, tex);
    m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, channel;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channel, 0);
    if (data)
    {
        GLenum format = GL_RED;
        if (channel == 1)
        {
            format = GL_RED;
        }
        else if (channel == 3)
        {
            format = GL_RGB;
        }
        else if (channel == 4)
        {
            format = GL_RGBA;
        }
        m_window->glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        m_window->glGenerateMipmap(GL_TEXTURE_2D);
        Texture texture = { tex, type, path };
        m_textures.push_back(texture);
    }
    else
    {
        qDebug() << "load texture error";
    }
    stbi_image_free(data);
    m_window->glBindTexture(GL_TEXTURE_2D, 0);
}