#include "pch.h"
#include "Header.h"	

#include <stdarg.h>

int Sum(int n, ...)
{
	va_list p;
	int sum = 0, count = 0;
	va_start(p, n);

	while (n--)
	{
		sum += va_arg(p, int);
	}

	va_end(p);

	return sum;
}

int NOD(int a, int b)
{
	while (a && b)
	{
		if (a >= b)
			a %= b;
		else
			b %= a;
	}

	return a | b;
}

int NOK(int a, int b)
{
	return (a * b) / NOD(a, b);
}

double Average(int n, double a,...)
{
	va_list p;

	double sum = 0, count = 0;

	va_start(p, n);
	while (n--)
	{
		sum += va_arg(p, double);
		count++;
	}

	va_end(p);

	return ((sum) ? sum / count : 0);
}

int Sub(int a, int b)
{
	return a - b;
}

int Mult(int a, int b)
{
	return a * b;
}


double Div(double a, double b)
{
	if (b != 0)
		return a / b;
}
