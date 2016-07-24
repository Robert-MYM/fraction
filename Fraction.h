#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cmath>
using namespace std;
int Function(int& a, int& b); //取a b的最大公约数

class Fraction {
	private:
		int fenzi;
		int fenmu;

	public:
		Fraction(int a = 0, int b = 1) {
			fenzi = a;
			fenmu = b;
		};
		Fraction(const Fraction& obj)
		{
			fenzi = obj.fenzi;
			fenmu = obj.fenmu;
		}

		int getfenzi() const
		{
			return fenzi;
		}
		int getfenmu() const
		{
			return fenmu;
		}
		void setfenzi(int i)
		{
			fenzi = i;
		}
		void setfenmu(int r) 
		{
			fenmu = r;
		}
		double getvalue() const
		{
			if (fenmu != 0)
				return fenzi / static_cast<double>(fenmu);
			else
				return static_cast<double>(fenzi);
		}

		void Simplification();
		void print();
		Fraction getReciprocal();

		friend istream& operator>> (istream& ,  Fraction& );
		friend ostream& operator<< (ostream& , const Fraction& );
		friend const Fraction operator+ (const Fraction& , const Fraction& );
		friend const Fraction operator- (const Fraction& , const Fraction& );
		friend const Fraction operator* (const Fraction& , const Fraction& );
		friend const Fraction operator/ (const Fraction& , const Fraction& );
		friend const bool operator> (const Fraction& , const Fraction& );
		friend const bool operator>= (const Fraction& , const Fraction& );
		friend const bool operator< (const Fraction& , const Fraction& );
		friend const bool operator<= (const Fraction& , const Fraction& );
		friend const bool operator== (const Fraction& , const Fraction& );
		friend const bool operator!= (const Fraction& , const Fraction& );
		friend const Fraction operator- (const Fraction& );
};

#endif // !__FRACTION_H

