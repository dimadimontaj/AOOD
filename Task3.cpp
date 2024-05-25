#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    setlocale (LC_ALL, "RUS");
    vector <int> rows;
    int n, m, max, str, stl, **arr, i, j;
    cout << "Введите число строк: ";
    cin >> n;
    cout << "Введите число столбцов: ";
    cin >> m;
    if ((n >= 100 || n < 1) || (m >= 50 || m < 1))
    {
        cout << "Ошибка, неверно введенные данные.";
        return 0;
    }
    arr = new int*[n];
    for (i = 0; i < n; i++)
        arr[i] = new int[m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                str = i + 1;
                stl = j + 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == max)
            {
                rows.insert(rows.end(), i + 1);
            }
        }
    }
    cout << "Максимальный элемент " << max << ", встречается в строках: ";
    for (i = 0; i < rows.size(); i++)
    {
        cout << rows[i] << " ";
    }
    return 0;
}
