#include <iostream>
#include <cmath>
const double EulerConstant = exp(1.0);
using namespace std;
double f(int b)
{
	double f = (pow(b, 2) * pow(EulerConstant, -0.5 * b));
	return f;
}
double result(double fa, double fb, double h, double sumeven, double sumodd)
{
	double result = ((h / 3) * (fa + 2 * sumeven + 4 * sumodd + fb));
	return result;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b, n;
	double h, sumeven, sumodd, fa, fb;
	cout << "Введите параметр b: ";
	cin >> b;
	a = 0, n = b;
	sumeven = sumodd = 0;
	h = (b - a) / n;
	fa = f(a);
	fb = f(b);
	for (b = 1; b < n; b++)
	{
		if (b % 2 == 0)
			sumeven += f(b);
		else
			sumodd += f(b);
	}
	cout << "Количество элементарных отрезков: " << n << endl;
	cout << "Результат: " << result(fa, fb, h, sumeven, sumodd) << " ";
}

