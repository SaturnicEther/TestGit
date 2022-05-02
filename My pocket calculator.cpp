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

int main()
{
	string input;
	mistype(input);
	input = exp();
	cout << "Result: " << input << endl;
	return 0;
}
bool mistype(string str)
{
	const int N = 137;
	char arr[N] = 
	{ 
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ',
        'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', '¨', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß',
        '~', '`', '!', '@', '#', '$', '&', '_', ':', ';','<', '>', ' ','¹', '?', '|', '{', '}'
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
double exp()
{
	double res;
	char op;
	res = term();
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
			return res;
		}
	}
}
double term()
{
	double res;
	char op;
	double temp;
	res = power();
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
				cerr << "Cannot be deleted on zero!";
				exit(-1);
			}
			res /= temp;
			break;
		default:
			cin.putback(op);
			return res;
		}
	}
}
//aaa
double power()
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
double fact()
{
	double res;
	char bracket;
	int sign = 1;
	bracket = cin.get();
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
	return sign * res;
}
double num()
{
	double res = 0.0;
	char digit;
	double k = 10.0;
	int sign = 1;
	digit = cin.get();
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
	return sign * res;
}
