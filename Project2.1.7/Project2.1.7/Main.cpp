#include<stdlib.h>;      
#include<iostream>;
#include <limits>;
#include"cmath";
#include <cassert>
#include <typeinfo>


#include"ODList.h"
using namespace std;


int intInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			finalnumd = finalnum;
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return intInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		cout << "Wrong input, try again\n";
		return intInpCheck();
	}
	if (doubleCheck == 0)
	{
		if (negativCheck == 1)
			return -finalnum;
		return finalnum;
	}
}
double doubleInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return doubleInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		finalnumd = finalnum / pow(10, (i - point - 1));
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
	if (doubleCheck == 0)
	{
		finalnumd = finalnum;
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
}
int answerCheck()
{
	int check = 0;
	do
	{
		cout << "Input your answer (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = cin.get();
		if (answer == 'y') check = 1;
		if (answer == 'n') check = -1;
	} while (check == 0);
	return check;
}

class MyException
{

public:

	MyException(string err)
	{
		ex_mes = err;
	}

	const char* getErr()
	{

		return ex_mes.c_str();
	}

private:
	string ex_mes;
};

void my_terminate()
{
	cout << "term_works\n";
	abort();
}


int main()
{
	set_terminate(my_terminate);
	cin.clear();
	cout << "Input anything to start" << endl;
	cin.get();
	system("cls");

	{

		ODList<int> the_intlist;
		ODList<int>::iterator list_intiter;

		the_intlist.add_front(3);

		the_intlist.add_front(3);

		the_intlist.print();

		the_intlist.remove_front();

		the_intlist.Shell();

		the_intlist.add_front(5);
		the_intlist.add_front(8);
		the_intlist.add_front(6);
		the_intlist.Shell();
		the_intlist.print();
	}

	{
		ODList<double> the_doublelist;
		ODList<double>::iterator list_doubleiter;

		the_doublelist.add_front(3.1);

		the_doublelist.add_front(3.1);

		the_doublelist.print();

		the_doublelist.remove_front();

		the_doublelist.Shell();

		the_doublelist.add_front(5.2);
		the_doublelist.add_front(8.3);
		the_doublelist.add_front(6.8);
		the_doublelist.Shell();
		the_doublelist.print();

		cout << endl;
	}

	{

		ODList<char> the_charlist;
		ODList<char>::iterator list_chariter;

		the_charlist.add_front('f');

		the_charlist.add_front('f');

		the_charlist.print();

		the_charlist.remove_front();

		the_charlist.Shell();

		the_charlist.add_front('d');
		the_charlist.add_front('s');
		the_charlist.add_front('a');
		the_charlist.Shell();
		the_charlist.print();
	}

	//try
	//{
	//	cout << "term_test" << endl;
	//	throw 1;
	//}
	//catch (char)
	//{
	//	cout << "term_doesn't_work";
	//}

	system("PAUSE");
	return 0;
}