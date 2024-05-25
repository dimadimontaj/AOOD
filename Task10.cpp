#include <iostream>
#include <stdlib.h>
using namespace std;
int maxel(int *arr)
{
	int max = arr[0];
	for (int i = 1; i < sizeof(arr); ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, *arr;
	cout << "Введите число элементов: ";
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << endl;
	}
	cout << "Максимальный элемент массива: " << maxel(arr);
}
