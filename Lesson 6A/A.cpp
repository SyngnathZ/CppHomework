#include<iostream>
#include<cstring>

using namespace std;

class Book
{
	public:

		~Book();
		void SetBook();		//�趨����
		void Display();								//��ʾ����	
		void Borrow();								//���麯��		
		void Return();								//���麯��

	private:

		char* Bookname;		//������Ա���������۸�ʹ�������
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
	Bookname = new char[40];	//��������������۸�ʹ�������
	cin >> Bookname;
	cin >> Price;
	cin >> Number;
}

void Book::Display()
{
	cout << "bookname:" << Bookname <<" "<< "price:" << Price << " " << "number:" << Number;			//��ʾ�������������۸�ʹ�������
}

void Book::Borrow()
{
	if (Number == 0)							//ʵ�ֽ���Ĺ��ܣ�������ǰͼ��������� 1������ʾ��ǰ��������	
	{
		cout << "û���˱����" << endl;
		abort();
	}
	Number -= 1;
	cout <<  Number ;
}

void Book::Return()
{
	Number += 1;								//ʵ�ֻ���Ĺ��ܣ�������ǰͼ��������� 1������ʾ��ǰ��������
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