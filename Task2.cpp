#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
  setlocale(LC_ALL, "RUS");
  int n, max, row, * arr, i;
  max = 1;
  row = 1;
  cout << "Введите число элементов: ";
  cin >> n;
  if ((n > 100 || n < 1))
  {
    cout << "Ошибка, неверно введенные данные.";
    return 0;
  }
  arr = new int [n];
  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 100;
    cout << arr[i] << endl;
    if (i > 0)
    {
      if (arr[i] > arr[i - 1])
      {
        row += 1;
      }
      else
      {
        if (row > max)
        max = row;
        row = 1;
      }
    }
  }
  cout << "Максимальная последовательность состоит из " << max << " элементов";
}
