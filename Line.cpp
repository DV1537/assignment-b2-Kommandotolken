#include "pch.h"
#include "Functions.h"
#include "Shape.h"
class Line : public Shape {
private:
	int numberOfPoints;
	float * coord;
	std::string type;
	float centerPos[2];
public:
	~Line() {
		delete[] coord;
		
	}

	Line(float * floatArray, int numberOfPoints)
	{
		
		type = "line";
		this->numberOfPoints = numberOfPoints;
		coord = new float[numberOfPoints];
		std::copy(floatArray, floatArray + numberOfPoints, coord);
	}


	
	void operator=(const Line &l)
	{
		delete[] coord;
		coord = new float[l.numberOfPoints];
		for (int i = 0; i < l.numberOfPoints; i++)
		{
			coord[i] = *(l.coord + i);
		}
		

	}


	void operator<<(const Shape &l) {

		std::cout << "The vertices for this line are: \n";
		for (int i = 0; i < 3; i += 2)
		{
			std::cout << "(" << coord[i] << " , " << coord[i + 1] << ") \n";
		}

	}


	
	std::string getType() {
		return type;
	}


	float area() {
		return -1;
	}




	float circumference() {
		return 0;
	}



	float * position() {
		
		float centerX = (coord[2] + coord[0]) / 2;
		float centerY = (coord[3] + coord[1]) / 2;
		
		centerPos[0] = centerX;
		centerPos[1] = centerY;
		return centerPos;

	}



	bool isConvex() {
		return false;
	}



	float distance(Shape *s) {
		float * sCoord = s->position() + 0;
		float d = sqrt(pow(sCoord[0] - coord[0], 2) + pow(sCoord[1] - coord[1], 2));;
		
		return d;
	}
	int getNumberOfPoints() {
		return 2;
	}
	void print() {
		std::cout.precision(3);
		std::cout << "The type is: " << getType() << "\n";
		std::cout << "The area is: " << area() << "\n";
		std::cout << "The circumference is: " << circumference() << "\n";
		std::cout << "The center coordinate is: " << position()[0] << " and " << position()[1] << "\n";
	}
};

