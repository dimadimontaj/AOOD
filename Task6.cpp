#include <iostream>
using namespace std;

void fill(int n, int* arr){
	cout << "Введите значения элементов массива: \n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}
void print(int n, int* arr){
	cout << "Вывод значений элементов массива: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << "\n";
}
void dif(int n, int* arr){
	int count = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] != arr[n-1])
			count++;
	}
	cout << "Число элементов массива, не равных последнему элементу массива: " << count << "\n";
}
void del(int n, int* arr){
	int max = arr[0];
	for (int i = 0; i < n; i++){
		if (arr[i] > max)
			max =arr[i];
	}
	auto itr = find(arr, arr + n, max);
	int ind = distance(arr, itr);
	for (int i = ind - 1; i < n - 1; i++)
		arr[i] = arr[i + 1];
	for (int i = 0; i < n - 1; i++)
		cout << arr[i] << "\t";
	cout << "\n";
}
 
int main(){
	setlocale(LC_ALL, "RUS");
	int n, choice;
	cout << "Введите число элементов: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Выберите операцию: \n1.Вввод значений массива\n2.Вывод массива\n3.Вывод количества чисел массива, отличных от последнего элемента массива\n4.Удаление числа перед максимальным числом\n0.Выход\n";
	cin >> choice;
	while (choice != 0){
		switch (choice){
		case 1:
			fill(n, arr);
			break;
		case 2:
			print(n, arr);
			break;
    case 3:
			dif(n, arr);
			break;
		case 4:
			del(n, arr);
			break;
		default:
			cout << "Ошибка, введите корректное число\n";
		}
		cout << "Выберите операцию\n";
		cin >> choice;
	}
}
