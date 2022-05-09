#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*функции идут по возрастанию по приоритету*/
double exp(); //сложение и вычитание
double term(); //умножение и деление
double power(); //возведение в степень
double fact(); //вычисление выражения в скобках
double num(); //чтение чисел с потока ввода

int main()
{
	double n;
	cout << "Enter the simple expession: "; //вводим простое выражение
	n = exp(); //используем результат функции exp()
	cout << "Result: " << n << endl;
	/*cout << "Then enter the complex expression: "; //вводим выражение посложнее
	n = exp();
	cout << "Result: " << n << endl;*/
	return 0;
}
double exp()
{
	double res;
	char op;
	res = term(); //результат равен результату функции term()
	while (true)
	{
		op = cin.get(); //вводим символ
		switch (op)
		{
		case '+':
			res += term(); //результат складываем с результатом функции term()
			break;
		case '-':
			res -= term(); //от результата отнимаем результат функции term()
			break;
		default:
			cin.putback(op); //если символ не является ни +, ни -, то он возвращается обратно в поток ввода
			return res; //возвращаем полученный результат
		}
	}
}
double term()
{
	double res;
	char op;
	double temp; //делитель
	res = power();
	while (true)
	{
		op = cin.get();
		switch (op)
		{
		case '*':
			res *= power(); //результат умножаем на результат функции power()
			break;
		case '/':
			temp = power(); //делитель равен результату функции power()
			if (temp == 0.0)//делитель равен нулю
			{
				cout << "Cannot be divided on zero!"; //на ноль делить нельзя!
				exit(-1); //завершение работы программы
			}
			res /= temp; //результат делим на результат функции power()
			break;
		default:
			cin.putback(op); //если символ не является ни * , ни / , то он возвращается обратно в поток ввода
			return res;
		}
	}
}
double power()
{
	char op;
	vector<double> v;
	v.push_back(fact()); //добавляем в конец вектора результат функции fact()
	while (true)
	{
		op = cin.get(); //
		while (op == ' ')
		{
			op = cin.get(); //
		}
		if (op == '^')
		{
			v.push_back(fact()); //добавляем в конец вектора результат функции fact()
		}
		else
		{
			cin.putback(op); //если символ не является ^ , то он возвращается обратно в поток ввода, и работа цикла прерывается
			break;
		}
		for (int I = v.size() - 1; I > 0; I--) //по убыванию
		{
			v[I - 1] = pow(v[I - 1], v[I]); //считываются основания и показатели степени, 
											//и основание-число с индеком I-1, возводится в степень числа с индексом I
		}
		return v[0]; //возвращаем нулевой элемент вектора, так как он является окончательным результатом работы цикла
	}
}
double fact()
{
	double res;
	char bracket; 
	int sign = 1;
	bracket = cin.get();
	while (bracket == ' ')
	{
		bracket = cin.get(); //вводим символ
	}
	switch (bracket)
	{
	case '-':
		sign = -1; //показатель отрицательного числа
	case '+':
		bracket = cin.get(); //если знак положительный, то ничего не меняется в значении sign, и работа условия прерывается
		break;
	}
	while (bracket == ' ')
	{
		bracket = cin.get(); //вводим символ
	}
	if (bracket == '(')
	{
		res = exp(); //результат приравнивается к результату функции exp()
		bracket = cin.get(); //ввод символа
		if (bracket != ')') //введённый символ не равен закрывающей скобке
		{
			cout << "Wrong bracket position!"; //неправильное положение скобок!
			exit(-1); //завершение работы программы
		}
	}
	else
	{
		cin.putback(bracket); //если символы не равны скобкам, то они возвращаются обратно в поток ввода
		res = num(); //а результат приравнивается к результату функции num()
	}
	return res * sign; //результат умножается на sign, и функция возвращает либо положительное, либо отрицательное число
}
double num()
{
	double res = 0.0;
	char digit;
	double k = 10.0;
	int sign = 1;
	digit = cin.get(); //вводим символ
	switch (digit)
	{
	case '-':
		sign = -1; //показатель отрицательного числа
		break; //работа условия прерывается
	default:
		if (digit != '+')
		{
			cin.putback(digit); //если знак не равен +, то он возвращаетмя обратно в поток ввода, и работа условия прерывается
		}
		break;
	}
	while (true)
	{
		digit = cin.get();
		while (digit == ' ')
		{
			digit = cin.get(); //пока символ равен пробелу, вводим символ
		}
		if (digit >= '0' && digit <= '9')
		{
			res = res * 10.0 + (digit - '0'); //пока символы равны цифрам от 0 до 9, первая цифра считывается, умножается на 10, 
			//и к ней прибавляется следующая, и снова повторяется этот цикл
		}
		else
		{
			cin.putback(digit); //если символ не является цифрой от 0 до 9, он возвращается в поток ввода, и цикл прерывается
			break;
		}
	}
	digit = cin.get(); //вводим символ
	if (digit == '.') //если символ равен точке
	{
		while (true)
		{
			digit = cin.get(); //
			while (digit == ' ')
			{
				digit = cin.get(); //пока символ равен пробелу, вводим символ
			}
			if (digit >= '0' && digit <= '9')
			{
				res += (digit - '0') / k;
				k *= 10.0; //если символы после точки равны цифрам от 0 до 9, то первая цифра делится на 10 и складыается
				//с результатом, полученным из предыдущего цикла, следующая цифра уже делится на 100 и складывается с res,
				//и так далее
			}
			else
			{
				cin.putback(digit);
				break; //если же символы после точки не равны цифрам от 0 до 9, 
			    //то они возвращаются обратно в поток ввода, и цикл прерывается
			}

		}
	}
	else
	{
		cin.putback(digit); //если символ не равен точке, то он возвращается в поток ввода
	}
	return sign * res; //функция возвращает результат, умноженный на sign-либо положительное, либо отрицательное число
}
