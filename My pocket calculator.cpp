#include <iostream>
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
	double res;
	char op;
	const int N = 256;
	int I = 0;
	int K = 50;
	double arr[N]{};
	double arr2[N]{};
	double full[N]{};
	int Z = I + K;
	for (I = 0; I < N; I++)
	{
		cin >> arr[I];
	}
	for (I=0; I < K; I++)
	{
		arr2[K] = fact();
	}
	while (true)
	{
		op = cin.get();
		while (op == ' ')
		{
			op = cin.get();
		}
		if (op == '^')
		{
			for (I = K; I < Z; I++)
			{
				full[I] = arr2[I - K];
			}
		}
		else
		{
			cin.putback(op);
			break;
		}
	}
	for (I = full[Z - 1]; I > 0; I--)
	{
		full[I - 1] = pow(full[I - 1], full[I]);
	}
	return full[0];
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
		if(digit>='0' && digit<='9')
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
