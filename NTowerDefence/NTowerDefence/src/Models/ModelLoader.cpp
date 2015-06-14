#include "ModelLoader.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>

ModelLoader::ModelLoader()
{

}

ModelLoader::~ModelLoader()
{

}

ModelPtr ModelLoader::LoadModel(const std::string& path, const ShaderPtr shader)
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_Quality);

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		throw std::logic_error(importer.GetErrorString());
	}

	auto model = ModelPtr(new Model(scene, shader, path.substr(0, path.find_last_of('/'))));

	return model;
}