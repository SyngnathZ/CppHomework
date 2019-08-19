#include<iostream>
#include<cstring>

using namespace std;

class Book
{
	public:

		~Book();
		void SetBook();		//设定函数
		void Display();								//显示函数	
		void Borrow();								//借书函数		
		void Return();								//还书函数

	private:

		char* Bookname;		//三个成员：书名、价格和存书数量
		double Price;
		int Number;
};

Book::~Book()
{
	delete[] Bookname;
	Bookname = NULL;
}

void Book::SetBook()
{	
	Bookname = new char[40];	//设置书的书名、价格和存书数量
	cin >> Bookname;
	cin >> Price;
	cin >> Number;
}

void Book::Display()
{
	cout << "bookname:" << Bookname <<" "<< "price:" << Price << " " << "number:" << Number;			//显示输出书的书名、价格和存书数量
}

void Book::Borrow()
{
	if (Number == 0)							//实现借书的功能，即将当前图书的数量减 1，并显示当前存书数量	
	{
		cout << "没书了别借了" << endl;
		abort();
	}
	Number -= 1;
	cout <<  Number ;
}

void Book::Return()
{
	Number += 1;								//实现还书的功能，即将当前图书的数量加 1，并显示当前存书数量
	cout << Number << endl;
}

int main()
{
	for (int i = 3; i > 0; i--)
	{
		Book B;
		B.SetBook();
		B.Display();
		cout << " ";
		B.Borrow();
		cout << " ";
		B.Return();
	}
}