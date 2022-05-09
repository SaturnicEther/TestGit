#include <iostream>
#include <vector>
using namespace std;
double exp();
double term();
double power();
double fact();
double num();

int main()
{
	double n;
	cout << "Enter expression: ";
	n = exp();
	cout << "Result: " << n << endl;
	cin.get();
	return 0;
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
		case '-':
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
			return res;
		}
	}
}
double power()
{
	char op;
	vector<double> v;
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
	}
	for (int I = v.size() - 1; I > 0; I--)
	{
		v[I - 1] = pow(v[I - 1], v[I]);
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
		}
		break;
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
	return res * sign;
}
