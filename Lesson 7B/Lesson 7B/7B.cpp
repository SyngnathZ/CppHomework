#include<iostream>
using namespace std;

class Real
{
public:
	Real(double r = 0)
	{
		a = r;
	}
	Real operator+(Real);
	Real operator-(Real);
	Real operator*(Real);
	Real operator/(Real);
	Real operator=(Real);
	void display()
	{
		cout << a;
	}
private:
	double a;
};

Real Real::operator+(Real x)
{
	Real temp;
	if (a + x.a<-3.4e38 || a + x.a>3.4e38)
	{
		cout << "overflow" << endl;
		abort();
	}
	temp.a = a + x.a;
	return temp;
}

Real Real::operator-(Real x)
{
	Real temp;
	if (a - x.a<-3.4e38 || a - x.a>3.4e38)
	{
		cout << "overflow" << endl;
		abort();
	}
	temp.a = a - x.a;
	return temp;
}

Real Real::operator*(Real x)
{
	Real temp;
	if (a * x.a<-3.4e38 || a * x.a>3.4e38)
	{
		cout << "overflow" << endl;
		abort();
	}
	temp.a = a * x.a;
	return temp;
}

Real Real::operator/(Real x)
{
	Real temp;
	if (a / x.a<-3.4e38 || a / x.a>3.4e38)
	{
		cout << "overflow" << endl;
		abort();
	}
	temp.a = a / x.a;
	return temp;
}

Real Real::operator=(Real x)
{
	a = x.a;
	return *this;
}

int main()
{
	double a, b;
	for (int i = 3; i > 0; i--)
	{
		cin >> a >> b;
		Real A(a), B(b),C;
		C = A + B;
		cout << "A+B="; C.display(); cout << " ";
		C = A - B;
		cout << "A-B="; C.display(); cout << " ";
		C = A * B;
		cout << "A*B="; C.display(); cout << " ";
		C = A / B;
		cout << "A/B="; C.display(); cout << endl;
	}
}