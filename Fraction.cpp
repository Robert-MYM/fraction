#include "Fraction.h"


int Function(int& a, int& b) {
	int mode = a%b;
	while (mode)
	{
		a = b;
		b = mode;
		mode = a%b;
	}
	return b;
}

void Fraction::Simplification() {
	int a = fenzi;
	int b = fenmu;
	int r = Function(a,b);
	fenzi = a / r;
	fenmu = b / r;
}


 istream& operator>>(istream& is, Fraction& obj)
{
	is >>obj.fenzi >> obj.fenmu;
	return is;
};

ostream& operator<<(ostream & os, const Fraction & obj)
{
	if (obj.fenmu == 0) 
		os << "此分数无意义" << endl;
	else
	{
		if (obj.fenzi == 0)
			os << 0<< endl;
		else
		{
			os << obj.fenzi << "/" << obj.fenmu << endl;
		}
	}
	return os;
}

void Fraction::print() {
	cout << *this;
}

Fraction Fraction::getReciprocal() {
	return Fraction(this->fenmu , this->fenzi);
}

const Fraction operator+ (const Fraction& x, const Fraction& y) {
	return Fraction((x.fenzi*y.fenmu+x.fenmu*y.fenzi) , (x.fenmu*y.fenmu));
}

const Fraction operator- (const Fraction& x, const Fraction& y) {
	return Fraction((x.fenzi*y.fenmu-x.fenmu*y.fenzi) , (x.fenmu*y.fenmu));
}

const Fraction operator* (const Fraction& x, const Fraction& y) {
	return Fraction(x.fenzi*y.fenzi , x.fenmu*y.fenmu);
}

const Fraction operator/ (const Fraction& x, const Fraction& y) {
	return Fraction(x.fenzi*y.fenmu , x.fenmu*y.fenzi);
}

const bool operator> (const Fraction& x, const Fraction& y) {
	if ((x - y).getvalue() > DBL_EPSILON)
		return true;
	else
		return false;
}

const bool operator>= (const Fraction& x, const Fraction& y) {
	if ((x - y).getvalue() < DBL_EPSILON)
		return false;
	else
		return true;
}

const bool operator< (const Fraction& x, const Fraction& y) {
	if ((y - x).getvalue() > DBL_EPSILON)
		return true;
	else
		return false;
}

const bool operator<= (const Fraction& x, const Fraction& y) {
	if ((y - x).getvalue() < DBL_EPSILON)
		return false;
	else
		return true;
}

const bool operator== (const Fraction& x, const Fraction& y) {
	if ((x - y).getvalue() > -DBL_EPSILON && (x - y).getvalue() < DBL_EPSILON)
		return true;
	else
		return false;
}

const bool operator!= (const Fraction& x, const Fraction& y) {
	if ((x - y).getvalue() > -DBL_EPSILON && (x - y).getvalue() < DBL_EPSILON)
		return false;
	else
		return true;
}

const Fraction operator- (const Fraction& x) {
	return Fraction(-(x.fenzi) , x.fenmu);
}