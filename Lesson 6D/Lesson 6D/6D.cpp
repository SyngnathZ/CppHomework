#include<iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};
class Line
{
	public:
		Line(double c, double d)
		{
			a = c;
			b = d;
		}
		void print()
		{
			cout << "y=" << a << "x+" << b << " ";
		}
		friend Point setpoint(Line &L1, Line &L2);
	private:
		double a, b;
};
Point setpoint(Line&L1, Line &L2)
{
	Point p;
	p.x = (L2.b - L1.b) / (L1.a - L2.a);
	p.y = (L1.a*L2.b - L2.a*L1.b) / (L1.a - L2.a);
	return p;
}
 
int main()
{
	double c1, c2, d1, d2;
	for (int i = 3; i > 0; i--)
	{
		cin >> c1 >> d1 >> c2 >> d2;
		Line line1(c1, d1);
		Line line2(c2, d2);
		Point setp;
		setp = setpoint(line1, line2);
		line1.print();
		line2.print();
		cout << "(" << setp.x << "," << setp.y << ")" << endl;
	}
}