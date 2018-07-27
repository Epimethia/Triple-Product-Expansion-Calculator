#pragma once

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

class ShaderLoader {
private:

	std::string ReadShader(char *filename);
	GLuint CreateShader(GLenum shaderType,
						std::string source,
						char* shaderName);

public:
	ShaderLoader(void);
	~ShaderLoader(void);
	GLuint CreateProgram(char* VertexShaderFilename,
						 char* FragmentShaderFilename);

	std::map<std::string, GLuint> Shaders;		//CAUSES MEMORY LEAK


};
