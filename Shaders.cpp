#pragma once
#include "Shaders.h"


Shaders::Shaders()
{
	programID = glCreateProgram();
}


Shaders::~Shaders()
{

}


void Shaders::attach()
{
	glLinkProgram(programID);

	int success;
	char infoLog[512];
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}		


void Shaders::LoadVertex(const char* shaderPath)
{
	std::string code;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		shaderFile.open(shaderPath);
		std::stringstream shaderStream;

		shaderStream << shaderFile.rdbuf();

		code = shaderStream.str();

		shaderFile.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* shaderCode = code.c_str();

	unsigned int vertexshader;
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &shaderCode, NULL);
	glCompileShader(vertexshader);

	int compileVertexSuccess;
	char compileVertexLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &compileVertexSuccess);
	if (!compileVertexSuccess)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, compileVertexLog);
		std::cout << "Shader compilation error\n" << compileVertexLog << std::endl;
		myShaders.push(vertexshader);
	}
	else
	{
		std::cout << "Shader compilation success\n" << std::endl;
	}

	glAttachShader(programID, vertexshader);
}


void Shaders::LoadFragment(const char* shaderPath)
{
	std::string code;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		shaderFile.open(shaderPath);
		std::stringstream shaderStream;

		shaderStream << shaderFile.rdbuf();

		code = shaderStream.str();

		shaderFile.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* shaderCode = code.c_str();

	unsigned int vertexshader;
	vertexshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexshader, 1, &shaderCode, NULL);
	glCompileShader(vertexshader);

	int compileVertexSuccess;
	char compileVertexLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &compileVertexSuccess);
	if (!compileVertexSuccess)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, compileVertexLog);
		std::cout << "Shader compilation error\n" << compileVertexLog << std::endl;
		myShaders.push(vertexshader);
	}
	else
	{
		std::cout << "Shader compilation success\n" << std::endl;
	}

	glAttachShader(programID, vertexshader);
}


void Shaders::use()
{
	glUseProgram(programID);
}


void Shaders::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}
void Shaders::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}
void Shaders::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void Shaders::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
