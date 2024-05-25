#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void fill(int n, int m, int arrint[100][50])
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
void fill(int n, int m, char arrchar[100][50])
{
	cout << "Введите элементы матрицы: \n";
	for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
    {
			cin >> arrchar[i][j];
		}
	}
}
void print(int n, int m, int arrint[100][50])
{
	cout << "Вывод элементов матрицы: \n";
	for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
    {
			cout <<setw(3) << arrint[i][j];
		}
		cout << endl;
	}
}
void print(int n, int m, char arrchar[100][50])
{
	cout << "Вывод элементов матрицы: \n";
	for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
    {
			cout << setw(3) << arrchar[i][j];
		}
		cout << endl;
	}
}
void sort(int n, int m, int arrint[100][50])
{
	int temp;
	for (int i = 0; i < n; i++)
  {
		for (int j = 0; j < m; j++)
    {
			if (arrint[n-1][i] < arrint[n-1][j])
      {
				for (int k = 0; k < n; k++){
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
			cout << setw(3) << arrint[i][j];
		}
		cout << endl;
	}
}
void sort(int n, int m, char arrchar[100][50])
{
	char temp;
	for (int i = 0; i < n; i++
       {
		for (int j = 0; j < m; j++)
    {
			if (arrchar[n - 1][i] < arrchar[n - 1][j])
      {
				for (int k = 0; k < n; k++)
        {
					temp = arrchar[k][i];
					arrchar[k][i] = arrchar[k][j];
					arrchar[k][j] = temp;
				}
			}
		}
	}
	cout << "Вывод отсортированной матрицы: \n";
	for (int i = 0; i < n; i++)
       {
		for (int j = 0; j < m; j++)
    {
			cout << setw(3) << arrchar[i][j];
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
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> m;
	cout << "Выберите тип данных: \n1. int \n2. char \n";
	cin >> choice;
	switch (choice)
  {
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
		default:
			cout << "Ошибка, неверно введены данные";
	}
	return 0;
}
