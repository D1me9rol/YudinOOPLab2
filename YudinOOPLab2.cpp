// YudinOOPLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "framework.h"
#include "YudinOOPLab2.h"
#include "YudinUtils.h"
#include "YudinShop.h"
#include  "pch.h"
#include <windows.h>


using namespace std;

void ShowMenu()
{
	cout << "0. Выход\n1. Добавить клиента\n2. Показать список клиентов\n3. Чтение из файла\n4. Сохранить в файл\n5. Очистить список посетителей\n6. Добавить оптового покупателя" << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	YudinShop Tools;
	int Option;

	do
	{
		ShowMenu();
		cin >> Option;
		switch (Option)
		{
		case 0:
			cout << "До свидания!" << endl;
			break;
		case 1:
			Tools.AddCustomer();

			break;
		case 2:
			Tools.ShowCustomersList();

			break;
		case 3:
			Tools.FileRead();

			break;
		case 4:
			Tools.FileSave();

			break;
		case 5:
			Tools.ClearCustomersList();

			break;
		case 6:
			Tools.AddWholeSaler();
			break;
		default:
			cout << "Введите цифру от 0 до 6!" << endl;
			break;
		}
	} while (Option != 0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
