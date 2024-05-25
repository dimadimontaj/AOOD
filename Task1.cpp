#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	float x, y, r, a, ras;
	cout << "r = ";
	cin >> r;
	cout << "a = ";
	cin >> a;
	if (r <= (a / 2))
	{
		cout << "Введены неверные данные";
		return 0;
	}
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	ras = sqrt((x * x) + (y * y));
	if ((ras <= r) && (abs(x) >= (a / 2)) && (abs(y) >= (a / 2)))
		cout << "Входит";
	else if (((ras <= r) && (abs(x) <= (a / 2)) && (abs(y) >= (a / 2))) ||
(((ras <= r) && (abs(y) <= (a / 2)) && (abs(x) >= (a / 2)))))
		cout << "Входит";
	else
		cout << "Не входит";
}
