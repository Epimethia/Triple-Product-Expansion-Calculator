#include "Dependencies\glm\vec3.hpp"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtx\string_cast.hpp"

#include <time.h>
#include <iostream>
#include <conio.h>


glm::vec3 GenerateVector() {
	auto Vec = glm::vec3(rand() % 101, rand() % 101, rand() % 101);
	std::cout << "Generated vector: " << glm::to_string(Vec) << std::endl;
	return Vec;
}

void CalcTripleProd(glm::vec3 _A, glm::vec3 _B, glm::vec3 _C) {
	std::cout << "\n";
	glm::vec3 LHS;
	glm::vec3 RHS;

	LHS = glm::cross(_A, glm::cross(_B, _C));									//Calculating left hand side using crossprod
	std::cout << "LHS Result: " << glm::to_string(LHS) << std::endl;

	RHS = (glm::dot(_A, _C) * _B) - (glm::dot(_A, _B) * _C);					//Calculating right hand side using dotprod
	std::cout << "RHS Result: " << glm::to_string(RHS) << std::endl;

	if (LHS == RHS) std::cout << "LHS is equal to RHS\n\n";
	else std::cout << "LHS is not equal to RHS\n\n";

	std::cout << "-------------------------------------------------------------------\n\n";
}



int main() {
	
	srand(static_cast<int>(time(NULL)));
	int NumIterations = 10;

	for (int i = 0; i < NumIterations; ++i) {
		CalcTripleProd(GenerateVector(), GenerateVector(), GenerateVector());
	}

	_getch();
	return 0;
}

