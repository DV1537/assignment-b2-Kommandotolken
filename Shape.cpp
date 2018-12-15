#include "pch.h"
#include "Shape.h"

/*float* Shape::getCoord() {
	return coord;
}
int Shape::getCounter() {
	return counter;
}*/
/*void Shape::operator+(Shape &s) {
	int otherCounter = s.getCounter();
	float * sCoords = s.getCoord();

	float * extraCoords = new float[this->counter + otherCounter];
	std::copy(coord, coord + counter, extraCoords);
	std::copy(sCoords, sCoords + otherCounter, extraCoords + counter);
	for (int i = 0; i < (this->counter + s.getCounter()); i++)
	{
		std::cout << *(extraCoords + i);
	}
	delete[] coord;
	coord = extraCoords;
	counter = (this->counter + s.getCounter());
}
void Shape::print() {
	
};*/