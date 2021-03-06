
#include "pch.h"
#include "Functions.h"
#include "Figure.h"
#include "Polygon.h"
#include <sstream>


int main(int argc, const char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int startingSize = 100;
	int capacity = startingSize;
	
	float a;

	int numberOfPoints = 0;
	int shapeCounter = 0;

	if (argc < 2)
	{
		std::cout << "You forgot to enter a filename.";
		return 1;
	}
	std::ifstream myInputFile;

	std::string line;
	char fileName[30];
	strcpy_s(fileName, argv[1]);
	myInputFile.open(fileName);

	if (myInputFile.fail())
	{
		std::cout << "There was an error opening the file.";
		return 1;
	}

	while (std::getline(myInputFile, line))
	{
		shapeCounter++;
	}
	myInputFile.clear();
	myInputFile.seekg(0, std::ios::beg);
	char c;
	while (myInputFile >> c)
	{
		if (!(isdigit(c)))
		{
			std::cout << "Wrong data.";
			return 1;
		}
	}
	float * floatArray = new float[startingSize];
	float * floatArray2 = nullptr;
	Shape **s = new Shape*[shapeCounter];
	myInputFile.clear();
	myInputFile.seekg(0, std::ios::beg);

	for (int i = 0; i < shapeCounter; ++i) {
		std::getline(myInputFile, line);
		std::stringstream stream(line);

		while (!stream.eof()) {
			stream >> a;

			if (numberOfPoints >= capacity)
			{
				floatArray2 = new float[capacity * 2];

				std::copy(floatArray, floatArray + capacity, floatArray2);

				delete[] floatArray;


				floatArray = floatArray2;
				capacity *= 2;

			}
			floatArray[numberOfPoints] = a;


			numberOfPoints++;
			delete[] floatArray2;
		}
		if (numberOfPoints % 2 != 0)
		{
			std::cout << "You missed a coordinate";
			return 1;
		}
		s[i] = new Polygon(floatArray, numberOfPoints);
		numberOfPoints = 0;

	}


	for (int i = 0; i < shapeCounter; i++)
	{
		s[i]->operator<<(*s[i]);
	}
	
	Figure figure(shapeCounter);
	for (int i = 0; i < shapeCounter; i++)
	{
		figure.addShape(s[i]);
	}
	
	figure.getBoundingBox();
		float locationToSend[2];
		locationToSend[0] = 0;
		locationToSend[1] = 0;
		figure.getClosest(locationToSend, shapeCounter);
		figure.printClosest(locationToSend, shapeCounter);
		for (int i = 0; i < shapeCounter; i++)
		{
			delete[] s[i];
		}
	
		delete[] s;
		s = nullptr;
	delete[] floatArray;

}



	