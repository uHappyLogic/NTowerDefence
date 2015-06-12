#pragma once

#include <memory>
#include <Base\GenericAssetsManager.h>

#include <GL/glew.h>

class Shader
{
public:
	Shader(GLuint programId);

	inline GLuint getId()
	{
		return programId;
	}

	virtual ~Shader();

private:
	GLuint programId;
};

typedef std::shared_ptr<Shader> ShaderPtr;
typedef GenericAssetsManager<ShaderPtr> ShaderManager;
typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;