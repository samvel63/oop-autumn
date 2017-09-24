#include <iostream>
#include <cmath>
#include "hexagon.h"

Hexagon::Hexagon() : Hexagon(0)
{
}

Hexagon::Hexagon(int32_t i) : side(i)
{
	std::cout << "Hexagon created: " << side << std::endl;
}

Hexagon::Hexagon(std::istream &is)
{
	is >> side;
}

Hexagon::Hexagon(const Hexagon& orig)
{
	std::cout << "Hexagon copy created" << std::endl;
	side = orig.side;
}

double Hexagon::Square()
{
	return (3 * sqrt(3) * double(side) * double(side)) / 2;
}

void Hexagon::Print() 
{
	std::cout << "Side = " << side << std::endl;
}

Hexagon::~Hexagon()
{
	std::cout << "Hexagon deleted" << std::endl;
}