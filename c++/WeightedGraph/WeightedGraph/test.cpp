#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in;
	in.open("graph.txt");

	int a, b, c, d;
	in >> a; 
	in >> b;
	in >> c;
	in >> d;

	std::cout << a << " " << b << std::endl;
	std::cout << c << " " << d << std::endl;

}
