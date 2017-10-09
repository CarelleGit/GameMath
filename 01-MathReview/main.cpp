#include <iostream>
#include <cmath>
#include "Mathutils.h"
using std::cout;


int main()
{

	//float val = sqr(2);
	//CLOSE===================
	cout << "CLOSED\n";
	cout << "1) ";
	cout << dbl(2) << "\n";
	cout << "2) ";
	cout << cube(4) << "\n";
	cout << "3) ";
	cout << degToRad(180) << "\n";
	cout << "4) ";
	cout << radToDeg(3.14) << "\n\n";
	//OPEN
	cout << "OPEN\n";
	cout << "1) ";
	cout << quad(0) << "\n";
	cout << "2) ";
	cout << L(0, 10, 0.5) << "\n";
	cout << "3) ";
	cout << D(0, 0, 0, 2) << "\n\n";
	while (true){}
}