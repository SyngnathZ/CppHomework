#include<iostream>
using namespace std;

class student
{
	public:
		void setscore(double s, double n)
		{
			score = s;
			total += score;
			number = n;
		}
		void setzero()
		{
			total = 0;
			score = 0;
			number = 0;
		}
		static double sum()
		{
			return total;
		}
		static double ave()
		{
			return total / number;
		}

	private:
		double score;
		static double total;
		static double number;
};

double student::total = 0;	//初始化分数计数器
double student::number = 0;	//初始化总人数

int main()
{
	int i, n;
	double s;
	for (int j = 4; j > 0; j--)
	{
		cin >> n;
		student STU;
		for (i = 0; i < n; i++)
		{
			cin >> s;
			STU.setscore(s, n);
		}
		cout << STU.sum() << " ";
		cout << STU.ave() << endl;
		STU.setzero();
	}
	
}