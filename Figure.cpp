#include "pch.h"
#include "Shape.h"
#include "Figure.h"
#include "Polygon.cpp"

Figure::Figure() 
{

}
Figure::Figure(int capacity)
{
	
	this->capacity = capacity;
	this->shapeArray = new Shape*[capacity];
}
Figure::~Figure() {
	delete[] shapeArray;
}
/*void Figure::addShape(Shape *s, float * floatArray, int numberOfPoints) {
	
	if (capacity <= numberOfFigures)
		capacity *= 2;
	s = new Polygon(floatArray, numberOfPoints);
	for (int i = numberOfFigures; i < capacity; i++)
	{
		shapeArray[i] = s;
	}
	numberOfFigures++;
}*/

void Figure::addShape(Shape *s) {
	if (numberOfFigures >= capacity)
	{

		Shape **shapeArrayTemp = new Shape*[numberOfFigures];
		std::copy(shapeArray, shapeArray + capacity, shapeArrayTemp);
		delete[] shapeArray;
		shapeArray = shapeArrayTemp;
	}

	shapeArray[numberOfFigures] = s;

	(*(static_cast<Polygon*>(shapeArray[numberOfFigures]))).print();
	numberOfFigures++;

	
}


float* Figure::getBoundingBox(){
	float boxCoord[4];
	//Get the lowest x value and y value, and the highest x and y value
	float boxHighestX = (*(static_cast<Polygon*>(shapeArray[0]))).getHighestX();
	float boxHighestY = (*(static_cast<Polygon*>(shapeArray[0]))).getHighestY();
	
	float boxLowestX = (*(static_cast<Polygon*>(shapeArray[0]))).getLowestX();
	float boxLowestY = (*(static_cast<Polygon*>(shapeArray[0]))).getLowestY();


	for (int i = 1; i <= (numberOfFigures-1); i++)
	{
		if (boxHighestX < (*(static_cast<Polygon*>(shapeArray[i]))).getHighestX())
		{
			boxHighestX = (*(static_cast<Polygon*>(shapeArray[i]))).getHighestX();
		}
		if (boxHighestY < (*(static_cast<Polygon*>(shapeArray[i]))).getHighestY())
		{
			boxHighestY = (*(static_cast<Polygon*>(shapeArray[i]))).getHighestY();
		}
		if (boxLowestX > (*(static_cast<Polygon*>(shapeArray[i]))).getLowestX())
		{
			boxLowestX = (*(static_cast<Polygon*>(shapeArray[i]))).getLowestX();
		}
		if (boxLowestY > (*(static_cast<Polygon*>(shapeArray[i]))).getLowestY())
		{
			boxLowestY = (*(static_cast<Polygon*>(shapeArray[i]))).getLowestY();
		}
	
		
	}
	boxCoord[0] = boxLowestX;
	boxCoord[1] = boxLowestY;
	boxCoord[2] = boxHighestX;
	boxCoord[3] = boxHighestY;
	std::cout << "The coordinates for the bounding box are: " << boxCoord[0] << " , " << boxCoord[1] << " and " << boxCoord[2] << " , " << boxCoord[3] << "\n";
	return boxCoord;
}

Shape* getClosest(float location[2], int n) {

}
