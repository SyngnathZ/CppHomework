#include<iostream>
using namespace std;

class Vector
{
	private:
		double *v;
		int len;
	public:
		Vector(int size);
		Vector(double*, int);
		~Vector();
		double &operator[](int i);
		Vector & operator =(const Vector &);
		friend Vector operator +(Vector &, Vector &);
		friend Vector operator - (Vector &, Vector &);
		friend double operator*(Vector &, Vector &);
		friend ostream & operator <<(ostream &output, Vector &);
		friend istream & operator >>(istream &input, Vector &);
};

Vector::Vector(int size)
{
	v = new double[size];
	len = size;
	for (int i = 0; i < size; i++)
	{
		v[i] = 0;
	}
}

Vector::Vector(double *C, int size)
{
	v = new double[size];
	len = size;
	for (int i = 0; i < len; i++)
	{
		v[i] = C[i];
	}

}

Vector::~Vector()
{
	delete []v;
	v = NULL;
	len = 0;
}

double & Vector::operator[](int i)
{
	return v[i];
}

Vector & Vector::operator=(const Vector &C)
{
	for (int i = 0; i < len; i++)
	{
		v[i] = C.v[i];
	}
	return *this;
}

Vector operator+(Vector &B, Vector &C)
{
	int len = B.len;
	double *vec = new double[len];
	for (int i = 0; i < len; i++)
	{
		vec[i] = B[i] + C[i];
	}
	return Vector(vec, len);
}

Vector operator-(Vector &B, Vector &C)
{
	int len = B.len;
	double *vec = new double[len];
	for (int i = 0; i < len; i++)
	{
		vec[i] = B[i] - C[i];
	}
	return Vector(vec, len);
}

double operator*(Vector &B, Vector &C)
{
	int len = B.len;
	double Real = 0;
	for (int i = 0; i < len; i++)
	{
		Real += B[i] * C[i];
	}
	return Real;
}

ostream & operator<<(ostream & output, Vector &C)
{
	output << "(";
	for (int i = 0; i < C.len; i++)
	{
		output << C[i];
		if (i == C.len - 1)
		{
			output << ")";
		}
		else 
		{
			output << ",";
		}
	}
	return output;
}

istream & operator>>(istream & input, Vector &C)
{
	for (int i = 0; i < C.len; i++)
	{
		input >> C[i];
	}
	return input;
}

int main()
{
	int n;
	double s;
	for (int i = 3; i > 0; i--)
	{
		cin >> n;
		Vector A(n);
		Vector B(n);
		Vector C(n);
		cin >> A;
		cin >> B;

		C = A + B;
		cout << "A=" << A << " ";
		cout << "B=" << B << " ";
		cout << "A+B=" << C << " ";
		C = A - B;
		cout << "A-B=" << C << " ";
		s = A * B;
		cout << "A*B=" << s << endl;
	}
}