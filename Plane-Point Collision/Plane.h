#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include <string>
#include <vector>
#include <iostream>

class Plane {
public:
	Plane(glm::vec3 _Normal, glm::vec3 _Origin, GLuint _Shader);
	void Render();
private:
	glm::vec3 NormalVec;
	glm::vec3 Origin;
	glm::mat4 ModelMatrix;
	glm::mat4 VPMat;
	GLuint PlaneVao;
	GLuint AxisVao;

	glm::mat4 VPMatrix;
	GLuint Shader;

};