#include "pch.h"
#include "Shape.h"
class Point : public Shape {
private:
	std::string type;
	float * coord;
	int numberOfPoints;
public:
	~Point() {
		delete[] coord;
	}
	 Point(float * floatArray, int numberOfPoints) {
		
		this->numberOfPoints = numberOfPoints;
		coord = floatArray;
		type = "point";
		std::copy(floatArray, floatArray + numberOfPoints, coord);
	}
	 void operator+(const float[])
	 {
		 std::cout << "This operator does not work on point.";
	 }

	 void operator=(const Point &p)
	 {
		 this->numberOfPoints = p.numberOfPoints;
		 delete[] coord;
		 coord = new float[p.numberOfPoints];
		 for (int i = 0; i < numberOfPoints; i++)
		 {
			 coord[i] = *(p.coord + i);
		 }
		
		

	 }

	 void operator=(const Shape &p)
	 {

		 std::cout << "You can only do this with points";


	 }
	
	 void operator<<(const Shape &p) {
		 std::cout << "The vertices for this point are: \n";
		 std::cout << "(" << coord[0] << " , " << coord[1];
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
		
		return coord;
	}



	bool isConvex() {
		return true;
	}


	float distance(Shape *s) {
		
		float * sCoord = s->position() + 0;
		float d = sqrt(pow(sCoord[0] - coord[0], 2) + pow(sCoord[1] - coord[1], 2));
		return d;
	}
	void print() {
		std::cout.precision(3);
		std::cout << "The type is: " << getType() << "\n";
		std::cout << "The area is: " << area() << "\n";
		std::cout << "The circumference is: " << circumference() << "\n";
		std::cout << "The center coordinate is: " << position()[0] << " and " << position()[1] << "\n";
	}
};
