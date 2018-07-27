#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


#include <time.h>
#include <iostream>
#include <conio.h>

#include "Plane.h"
#include "ShaderLoader.h"

ShaderLoader sl;
GLuint Shader;
Plane* p1;

GLuint AxisVAO;



void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	Shader = sl.CreateProgram("Shaders/Vertex Shader.vs", "Shaders/Fragment Shader.fs");
	p1 = new Plane(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(), Shader);

	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
}

void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	p1->Render();

	glLineWidth(2.0f);
	glBegin(GL_LINES);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
	glVertex3f(0.0f, 10.0f, 0.0f); // ending point of the line

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
	glVertex3f(10.0f, 0.0f, 0.0f); // ending point of the line

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
	glVertex3f(0.0f, 10.0f, 10.0f); // ending point of the line
	glEnd();

	
	glutSwapBuffers();
}

void update(void) {

	glutPostRedisplay();
}

void Exit(void) {

} 

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Window");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glewInit();
	init();
	glutDisplayFunc(render);
	glutIdleFunc(update);
	glutIgnoreKeyRepeat(1);
	glutCloseFunc(Exit);
	glutMainLoop();
	return 0;
}