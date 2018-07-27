#include "Plane.h"

Plane::Plane(glm::vec3 _Normal, glm::vec3 _Origin, GLuint _Shader) {
	GLfloat vertices[] = {
		// Positions				// Colors				//Normal Coords
		-0.25f,  0.25f, 0.0f,		0.07f, 0.3f, 0.6f,		0.0f, 1.0f, 0.0f,	// Top Left
		0.25f,  0.25f, 0.0f,		0.07f, 0.3f, 0.6f,		0.0f, 1.0f, 0.0f,	// Top Right
		0.25f, -0.25f, 0.0f,		0.07f, 0.3f, 0.6f,		0.0f, 1.0f, 0.0f,	// Bottom Right
		-0.25f, -0.25f, 0.0f,		0.07f, 0.3f, 0.6f,		0.0f, 1.0f, 0.0f,	// Bottom Left

	};

	

	GLuint indices[]{
		0, 1, 2,		//First Triangle
		0, 2, 3			//Second Triangle
	};

	GLuint VBO;
	GLuint EBO;

	//Generating buffers
	glGenVertexArrays(1, &PlaneVao);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(PlaneVao);

	//Binding and setting buffer data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Enabling the positional floats
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat),
		(GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Enabling color floats
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//Enabling normal floats
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat),
		(GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	//Generating EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
		GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	VPMat = 
		glm::perspective(0.0f, 1.0f, 0.5f, 100.0f) 
		* glm::lookAt(
			glm::vec3(0.0f, 0.0f, 2.0f), 
			glm::vec3(0.0f, 0.0f, 0.0f), 
			glm::vec3(0.0f, 1.0f, 0.0f)
		);

	glm::mat4 TranslationMatrix =
		glm::translate(
		glm::mat4(),
		glm::vec3(Origin)
		);

	glm::mat4 RotationMatrix =
		glm::rotate(
			glm::mat4(),
			glm::radians(30.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		) * 
		glm::rotate(
			glm::mat4(),
			glm::radians(-30.0f),
			glm::vec3(1.0f, 0.0f, 0.0f)
		);

	ModelMatrix = TranslationMatrix * RotationMatrix;// *ScaleMatrix;

	Shader = _Shader;
}

void Plane::Render() {
	glUseProgram(Shader);

	//Binding the array
	glBindVertexArray(PlaneVao);

	//Setting back face culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);

	//Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glm::mat4 MVP = VPMatrix * ModelMatrix;

	GLuint  transformLoc = glGetUniformLocation(Shader, "MVP");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glUniformMatrix4fv(glGetUniformLocation(Shader, "MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniformMatrix4fv(glGetUniformLocation(Shader, "model"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
	glUniform3fv(glGetUniformLocation(Shader, "camPos"), 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));

	//Drawing the entity
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



	//Disabling backface culling
	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);

	//Clearing the vertex array
	glBindVertexArray(0);
}
