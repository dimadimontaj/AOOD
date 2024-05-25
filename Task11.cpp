#define NOMINMAX

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <stdexcept>
#include <windows.h>

struct order
{
	unsigned int number = 0;
	std::string name;
	std::string orderItem;
	unsigned short amount = 0;
	unsigned int totalPrice = 0;
};

//Прототипы функций
void readFile(std::string filename, std::vector<order>& database);
void writeFile(std::string filename, std::vector<order>& database);
void input(std::vector<order>& database);
void sortByNum(std::vector<order>& database);
void search(std::vector<order>& database, unsigned short number);
void print(std::vector<order>& database);

int main()
{
	setlocale(LC_ALL, "ru_RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	enum MenuMode
	{
		Exit,
		Input,
		Sort,
		Print,
		Search,
		Write,
		Read
	};
	unsigned short menu;
	std::vector<order> database;
	std::string filename;
	std::cout << "Введите имя файла или путь к файлу для работы:\n";
	std::cin >> filename;
	do
	{
		std::cout << "\nВыберите режим работы программы:" << std::endl;
		std::cout << "1 - ввод данных через консоль" << std::endl;
		std::cout << "2 - сортировка данных по номеру заказа" << std::endl;
		std::cout << "3 - вывод данных на экран" << std::endl;
		std::cout << "4 - поиск по номеру заказа" << std::endl;
		std::cout << "5 - запись данных в файл " << filename << std::endl;
		std::cout << "6 - чтение данных из файла " << filename << std::endl;
		std::cout << "0 - выход из программы" << std::endl;
		std::cin >> menu;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Выбор в меню осуществляется только цифрами от 0 до 6" << std::endl;
			continue;
		}
		switch (menu)
		{
		case MenuMode::Input:
			input(database);
			break;
		case MenuMode::Sort:
			sortByNum(database);
			std::cout << "Данные отсортированы" << std::endl;
			break;
		case MenuMode::Print:
			print(database);
			break;
		case MenuMode::Search:
			int num;
			std::cout << "Введите номер заказа для поиска: ";
			std::cin >> num;
			search(database, num);
			break;
		case MenuMode::Write:
			writeFile(filename, database);
			break;
		case MenuMode::Read:
			readFile(filename, database);
			break;
		case MenuMode::Exit:
			return 0;

		default:
			std::cout << "Допускаются только цифры от 0 до 6" << std::endl;
			break;
		}
	} while (menu != 0);
	return 0;
}

void readFile(std::string filename, std::vector<order>& database)
{
	database.clear(); //очистка старых данных в оперативной памяти
	std::ifstream file;
	try
	{
		file.open(filename);
		if (!file) throw std::invalid_argument("error opening file");

		order tmp;
		std::string input;
		while (true)
		{
			if (!std::getline(file, input, '|')) break;
			tmp.number = std::stoi(input);
			std::getline(file, input, '|');
			tmp.name = input;
			std::getline(file, input, '|');
			tmp.orderItem = input;
			std::getline(file, input, '|');
			tmp.amount = std::stoi(input);
			std::getline(file, input, '\n');
			tmp.totalPrice = std::stoi(input);
			database.push_back(tmp);
		}
		file.close();
		std::cout << "Успешное чтение из файла" << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
void writeFile(std::string filename, std::vector<order>& database)
{
	std::ofstream file;
	try
	{
		file.open(filename);
		if (!file) throw std::invalid_argument("error opening file");
		for (int i = 0; i < database.size(); i++)
		{
			file << database[i].number << "|" << database[i].name << "|" << database[i].orderItem << "|" << database[i].amount << "|" << data-base[i].totalPrice << std::endl;
		}
		file.close();
		std::cout << "Успешная запись в файл" << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void input(std::vector<order>& database)
{
	order tmp;
	bool switch_on = true;
	while (switch_on)
	{
		std::cout << "Введите номер операции, 1 - добавить элемент, 0 - выход из цикла\n";
		std::cin >> switch_on;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Допускаются только цифры от 0 до 1\n" << std::endl;
			continue;
		}
		std::string input;
		switch (switch_on)
		{
		case 1:
			std::cout << "Номер заказа: ";
			std::cin >> tmp.number;
			std::cout << "ФИО заказчика: ";
			std::cin.ignore();
			std::getline(std::cin, tmp.name);
			std::cout << "Наименование товара: ";
			std::getline(std::cin, tmp.orderItem);
			std::cout << "Количество товара: ";
			std::cin >> tmp.amount;
			std::cout << "Сумма заказа: ";
			std::cin >> tmp.totalPrice;
			database.push_back(tmp);
			break;
		default:
			break;
		}
	}
}
void sortByNum(std::vector<order>& database)
{
	std::sort(database.begin(), database.end(), [](order o1, order o2) -> bool {return o1.number < o2.number; });
}

void search(std::vector<order>& database, unsigned short number)
{
	order find;
	find.number = number;
	sortByNum(database);
	if (std::binary_search(database.begin(), database.end(), find, [](order o1, order o2) -> bool {return o1.number < o2.number; }))
	{
		std::cout << "Искомый элемент найден в массиве данных" << std::endl;
		find = database[std::lower_bound(database.begin(), database.end(), find, [](order o1, order o2) -> bool {return o1.number < o2.number; }) - data-base.begin()];
		std::cout << find.number << "|" << find.name << "|" << find.orderItem << "|" << find.amount << "|" << find.totalPrice << std::endl;
	}
	else std::cout << "Искомый элемент не найден в массиве данных" << std::endl;
}

void print(std::vector<order>& database)
{
	sortByNum(database);
	for (int i = 0; i < database.size(); i++)
	{
		std::cout << database[i].number << "|" << database[i].name << "|" << database[i].orderItem << "|" << database[i].amount << "|" << data-base[i].totalPrice << std::endl;
	}
}
