#include "Fraction.h"
#include <iostream>
using namespace std;

int main(void)
{
	Fraction f1(2, 3), f2(5,6);
	Fraction f3;
	f1.print();
	f2.print();
	f3 = f1 + f2;
	f3.print();

	return 0;
}