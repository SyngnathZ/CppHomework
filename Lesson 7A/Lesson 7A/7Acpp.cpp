#include<iostream>
using namespace std;

class RMB
{
	public:
		RMB(int y, int j, int f, bool mark = false);
		RMB(double x);
		operator double() const;
		friend ostream&operator<<(ostream&, const RMB &);
		friend istream&operator>>(istream&, RMB&);

	private:
		int yuan = 0, jiao = 0, fen = 0;
		bool mark;
};

RMB::RMB(int y, int j, int f, bool m)
{
	yuan = y;
	jiao = j;
	fen = f;
	mark = m;
}

RMB::RMB(double x)
{
	if (x < 0)
	{
		mark = 1;
		x = -x;
		int n = int((x + 0.005) * 100);
		yuan = n / 100;
		jiao = (n - yuan * 100) / 10;
		fen = n - yuan * 100 - jiao * 10;
	}
	else
	{
		mark = 0;
		int n = int((x + 0.005) * 100);
		yuan = n / 100;
		jiao = (n - yuan * 100) / 10;
		fen = n - yuan * 100 - jiao * 10;
	}
}

RMB::operator double() const
{
	double x = yuan + jiao / 10.0 + fen / 100.0;
	if (mark) { x = -x; }
	return x;
}

ostream & operator<<(ostream & output, const RMB &r)
{
	if (r.mark)
		output << "-";
	output << r.yuan <<"."<< r.jiao  << r.fen << "yuan ";
	return output;
}

istream & operator>>(istream & input, RMB &r)
{
	input >> r.yuan;
	input >> r.jiao;
	input >> r.fen;
	return input;
}

int main()
{
	int a1, a2, a3, b1, b2, b3;
	double c;
	for (int i = 4; i > 0; i--)
	{
		cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> c;
		RMB a = RMB(a1, a2, a3);
		RMB b = RMB(b1, b2, b3);
		cout << "a=" << RMB(a1, a2, a3) << "b=" << RMB(b1, b2, b3) << "c=" << RMB(c)
			<< "a+c=" << double(a + c) << " "
			<< "a-b=" << double(a - b) << " "
			<< "b*2=" << double(b * 2) << " "
			<< "a*0.5=" << double(a * 0.5) << endl;
	}
}