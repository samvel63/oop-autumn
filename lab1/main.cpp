#include <cstdlib>
#include "triangle.h"

int main(int argc, char** argv)
{
	Figure *ptr = new Triangle(std::cin);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;
	return 0;
}