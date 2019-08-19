#include<iostream>
using namespace std;

class nauticalmile_kilometer
{
	public:
		nauticalmile_kilometer(double k, double m)
		{
			kilometer = k;
			meter = m;
		}
		void print()
		{
			cout << "kilometer=" << kilometer << " " << "meter=" << meter << " ";
		}
		operator double()
		{
			return ( meter / 1000 + kilometer ) / 1.852;
		}
	private:
		double kilometer, meter;
};

int main()
{
	double K, M;
	for (int i = 3; i > 0; i--)
	{
		cin >> K >> M;
		nauticalmile_kilometer Nau(K, M);
		Nau.print();
		cout << "nauticalmile=" << double(Nau) << endl;
	}
}