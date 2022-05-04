#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

bool mistype(string);
double exp();
double term();
double power();
double fact();
double num();
//double double double
int main()
{
	cout << "Enter the string: ";
	string output;
	mistype(output);
	double doutput;
	doutput = exp();
	cout << "Result: " << doutput << endl;
	return 0;
}
bool mistype(string str)
{
	const int N = 137;
	char arr[N] = 
	{ 
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я',
        'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я',
        '~', '`', '!', '@', '#', '$', '&', '_', ':', ';','<', '>', ' ','№', '?', '|', '{', '}'
	};
	str = "((19*8)-15+2^2/1.5)*7";
	int found;
	for (int I = 0; I < N; I++)
	{
		found = str.find(arr[I]);
		if (found != string::npos)
		{
			cerr << "A mistype!";
			exit(-1);
		}
		else
		{
			return false;
		}
	}
	return false;
}
string exp()
{
	double res;
	char op;
	res = term();
	string s = to_string(res);
	while (true)
	{
		op = cin.get();
		switch (op)
		{
		case '+':
			res += term();
			break;
		case '-':
			res -= term();
			break;
		default:
			cin.putback(op);
			return s;
		}
	}
}
string term()
{
	double res;
	char op;
	double temp;
	res = power();
	string s = to_string(res);
	while (true)
	{
		op = cin.get();
		switch (op)
		{
		case '*':
			res *= power();
			break;
		case '/':
			temp = power();
			if (temp == 0.0)
			{
				cerr << "Cannot be divided on zero!";
				exit(-1);
			}
			res /= temp;
			break;
		default:
			cin.putback(op);
			return s;
		}
	}
}
string power()
{
	char op;
	string v = "((19*8)-15+2^2/1.5)*7";
	v.push_back(fact());
	while (true)
	{
		op = cin.get();
		while (op == ' ')
		{
			op = cin.get();
		}
		if (op == '^')
		{
			v.push_back(fact());
		}
		else
		{
			cin.putback(op);
			break;
		}
		for (int I = v.size() - 1; I > 0; I--)
		{
			v[I - 1] = pow(v[I - 1], v[I]);
		}
	}
	return v[0];
}
string fact()
{
	double res;
	char bracket;
	int sign = 1;
	bracket = cin.get();
	string s = to_string(res * sign);
	while (bracket == ' ')
	{
		bracket = cin.get();
	}
	switch (bracket)
	{
	case '-':
		sign = -1;
		break;
	case '+':
		bracket = cin.get();
		break;
	}
	while (bracket == ' ')
	{
		bracket = cin.get();
	}
	if (bracket == '(')
	{
		res = exp();
		bracket = cin.get();
		if (bracket != ')')
		{
			cerr << "Wrong bracket position!";
			exit(-1);
		}
	}
	else
	{
		cin.putback(bracket);
		res = num();
	}
	return s;
}
string num()
{
	double res = 0.0;
	char digit;
	double k = 10.0;
	int sign = 1;
	digit = cin.get();
	string n = to_string(sign * res);
	switch (digit)
	{
	case '-':
		sign = -1;
		break;
	default:
		if (digit != '+')
		{
			cin.putback(digit);
			break;
		}
	}
	while (true)
	{
		digit = cin.get();
		while (digit == ' ')
		{
			digit = cin.get();
		}
		if (digit >= '0' && digit <= '9')
		{
			res = res * 10.0 + (digit - '0');
		}
		else
		{
			cin.putback(digit);
			break;
		}
	}
	digit = cin.get();
	if (digit == '.')
	{
		while (true)
		{
			digit = cin.get();
			while (digit == ' ')
			{
				digit = cin.get();
			}
			if (digit >= '0' && digit <= '9')
			{
				res += (digit - '0') / k;
				k *= 10.0;
			}
			else
			{
				cin.putback(digit);
				break;
			}
		}
	}
	else
	{
		cin.putback(digit);
	}
	return n;
}
