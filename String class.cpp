#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	string eightymax;
	string endless;
	string enter;
	string Enter80()
	{
		cin >> eightymax;
		return eightymax;
	}
	string Enterel()
	{
		cin >> endless;
		return endless;
	}
	string Enteret()
	{
		string m;
		cin >> m;
		enter = m;
		return enter;
	}
	string Get80()
	{
		cout << eightymax;
		return eightymax;
	}
	string Getel()
	{
		cout << endless;
		return endless;
	}
	string Getet()
	{
		cout << enter;
		return enter;
	}
	~String()
	{}
};
int main()
{
	String str;
	string a, e8, el, et;
	int uc;
	int c = 0;
	cout << "1. Enter a string(80 characters max): " << endl;
	cout << "2. Enter a string of any length: " << endl;
	cout << "3. Initializing a string from your input: " << endl;
	cout << "4. Show the amount of strings entered: " << endl;
	cout << "5. Exit" << endl;
	cin >> uc;
	do
	{
		switch (uc)
		{
		case 1:
		{
			cout << "Enter a string(80 symbols max): ";
			str.Enter80();
			str.Get80();
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Enter a string of any length: ";
			str.Enterel();
			str.Getel();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Initialization through user input: ";
			str.Enteret();
			str.Getet();
			cout << endl;
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			cout << "Goodbye!";
			break;
		}
		default:
		{
			cout << "Wrong menu item!" << endl;
		}
		}
	}while (uc != 5);
	return 0;
}