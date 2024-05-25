#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
template <class T>
void fill(int n, int m, T arrint[100][50]) 
{
	cout << "Введите элементы матрицы: \n";
	for (int i = 0; i < n; i++) 
  {
		for (int j = 0; j < m; j++) 
    {
			cin >> arrint[i][j];
		}
	}
}
template <class T>
void print(int n, int m, T arrint[100][50])
{
	cout << "Вывод элементов матрицы: \n";
	for (int i = 0; i < n; i++) 
  {
		for (int j = 0; j < m; j++) 
    {
			cout << setw(4) << arrint[i][j];
		}
		cout << endl;
	}
}
template <class T>
void sort(int n, int m, T arrint[100][50]) 
{
	T temp;
	for (int i = 0; i < n; i++) 
  {
		for (int j = 0; j < m; j++) 
    {
			if (arrint[n - 1][i] < arrint[n - 1][j]) 
      {
				for (int k = 0; k < n; k++) 
        {
					temp = arrint[k][i];
					arrint[k][i] = arrint[k][j];
					arrint[k][j] = temp;
				}
			}
		}
	}
	cout << "Вывод отсортированной матрицы: \n";
	for (int i = 0; i < n; i++) 
  {
		for (int j = 0; j < m; j++) 
    {
			cout << setw(4) << arrint[i][j];
		}
		cout << endl;
	}
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	int n, m, choice;
	int arrint[100][50];
	char arrchar[100][50];
	float arrfloat[100][50];
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> m;
	cout << "Выберите тип данных: \n1.int\n2.char\n3.float\n";
	cin >> choice;
	switch (choice) {
case 1:
		fill(n, m, arrint);
		print(n, m, arrint);
		sort(n, m, arrint);
		break;
	case 2:
		fill(n, m, arrchar);
		print(n, m, arrchar);
		sort(n, m, arrchar);
		break;
	case 3:
		fill(n, m, arrfloat);
		print(n, m, arrfloat);
		sort(n, m, arrfloat);
		break;
	default:
		cout << "Ошибка, введены неверные данные";
	}
	return 0;
}

