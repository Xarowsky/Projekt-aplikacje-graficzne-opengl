#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h> 
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>


class Shaders
{
public:
	unsigned int programID;
	std::stack<unsigned int> myShaders;

	void use();
	void attach();

	Shaders();
	~Shaders();

	void LoadVertex(const char* shaderPath);
	void LoadFragment(const char* shaderPath);

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;

};