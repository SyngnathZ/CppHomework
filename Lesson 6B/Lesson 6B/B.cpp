#include<iostream>
using namespace std;

class Box
{
	public:
		Box(double l, double w, double h)
		{
			length = l;
			width = w;
			height = h;
		}
		void Volume()
		{
			cout << length * width * height << endl;
		}
	private:
		double length, width, height;
};

int main()
{	
	double l, w, h;
	for (int i = 3; i > 0; i--)
	{
		cin >> l >> w >> h;
		Box box(l, w, h);
		box.Volume();
	}
}