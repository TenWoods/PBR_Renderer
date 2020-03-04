#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "RenderObject.h"
#include "Mesh.h"

class Model : public RenderObject
{
private :
	std::vector<Texture> loaded_texture;
	std::vector<Mesh> meshes;
	std::string directory;
	//bool gammaCorrection;
	void LoadModel(std::string const& path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> LoadTextures(aiMaterial* mat, aiTextureType type, TEXTURE_TYPE typeName);
public :
	Model() : RenderObject()
	{

	}
	Model(std::string const& path, Render* window);
	void Draw(QOpenGLShaderProgram* shader) override;
	void AddTexture(std::string path, TEXTURE_TYPE type) override
	{

	}
};

