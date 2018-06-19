#include <iostream>

using namespace std;

class fraction
{
    public :

	int numerator;
	int denominator;

	fraction()
	{
		numerator = 1;
		denominator =1;
	}

	fraction(int num, int den)
	{
		numerator = num;
		denominator = den;
	}

	fraction operator+(fraction ob);
	fraction operator*(fraction ob);
	fraction operator-(fraction ob);
	fraction operator/(fraction ob);

	bool operator<(fraction ob);
	bool operator>(fraction ob);
	bool operator==(fraction ob);
	bool operator<=(fraction ob);
	bool operator>=(fraction ob);

	bool operator--();

	void show();
};

bool fraction::operator--()
{
	numerator = numerator - denominator;
}

bool fraction::operator>=(fraction ob)
{
	return numerator * ob.denominator >= ob.numerator * denominator;
}

bool fraction::operator<=(fraction ob)
{
	return numerator * ob.denominator <= ob.numerator * denominator;
}

bool fraction::operator==(fraction ob)
{
	return numerator * ob.denominator == ob.numerator * denominator;
}

bool fraction::operator>(fraction ob)
{
	return numerator * ob.denominator > ob.numerator * denominator;
}

bool fraction::operator<(fraction ob)
{
	return numerator * ob.denominator < ob.numerator * denominator;
}

fraction fraction::operator/(fraction ob)
{
	fraction temp;
	temp.denominator = denominator * ob.numerator;
	temp.numerator = numerator * ob.denominator;
	return temp;
}

fraction fraction::operator-(fraction ob)
{
	fraction temp;
	temp.denominator = denominator * ob.denominator;
	temp.numerator = numerator * ob.denominator - ob.numerator * denominator;
	return temp;
}

fraction fraction::operator*(fraction ob)
{
	fraction temp;
	temp.denominator = denominator * ob.denominator;
	temp.numerator = numerator * ob.numerator;
	return temp;
}

fraction fraction::operator+(fraction ob)
{
	fraction temp;
	temp.denominator = denominator * ob.denominator;
	temp.numerator = numerator*ob.denominator + ob.numerator*denominator;
    return temp;
}

void fraction::show()
{
	cout << numerator << "/" << denominator << endl;
}

int main()
{
	fraction ob1(4,5);
	fraction ob2(5,4);

	fraction ob3 = ob1 + ob2;
	ob3.show();

	ob3 = ob1 * ob2;
	ob3.show();

	ob3 = ob1 - ob2;
	ob3.show();

	ob3 = ob1 / ob2;
	ob3.show();

	--ob1;
	ob1.show();

	cout << "ob1 is greater than ob2 " << (ob1 > ob2) << endl;
	cout << "ob1 is less than ob2 " << (ob1 < ob2) << endl;
	cout << "ob1 is equal to ob2 " << (ob1 == ob2) << endl;
	cout << "ob1 is less than equal to ob2 " << (ob1 <= ob2) << endl;
	cout << "ob1 is greater than eqaul to ob2 " << (ob1 >= ob2) << endl;

	return 0;
}
