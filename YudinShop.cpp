#include "YudinShop.h"
#include "pch.h"
#include <typeinfo>
using namespace std;

void YudinShop::AddCustomer()
{
	/*string name;
	int age;
	double avg_check;

	cout << "Введите имя: ";
	cin.ignore();
	getline(cin, name);

	cout << "Введите возраст: ";
	cin >> age;

	cin.ignore();
	cout << "Введите среднее значение чека: ";
	cin >> avg_check;*/
	shared_ptr<YudinCustomer> Visitor = make_shared<YudinCustomer>();
	Visitor->EnterData();
	Visitors.push_back(Visitor);
}

void YudinShop::AddWholeSaler()
{
	shared_ptr<YudinWholesaler> Wholesaler = make_shared<YudinWholesaler>();
	Wholesaler->EnterData();
	Visitors.push_back(Wholesaler);
}



void YudinShop::ShowCustomersList()
{
	cout << "------------------------------" << endl;
	if (Visitors.size() > 0)
	{
		//cout << Visitors.size() << endl;
		for (auto& Visitor : Visitors)
		{
			cout << typeid(Visitor).name() << endl;
			Visitor.get()->ShowData();
		}
	}
	else cout << "Список покупателей пуст!" << endl;
	cout << "------------------------------" << endl;
}

void YudinShop::FileRead()
{
	//Visitors.clear();
	//int CustomersAmount;
	string FileName;
	
	cout << "Введите название файла для чтения: " << endl;
	cin >> FileName;

	CString cstrFileName;
	cstrFileName = FileName.c_str();
	CFile fin;//(cstrFileName, CFile::modeRead);

	if (fin.Open(cstrFileName, CFile::modeRead))
	{
		CArchive ar(&fin, CArchive::load);
		int amount;
		ar >> amount;

		if (amount > 0)
		{
			for (int i = 0; i < amount; i++)
			{
				YudinCustomer* Visitor;
				ar >> Visitor;
				shared_ptr<YudinCustomer> ptr(Visitor);
				Visitors.push_back(ptr);
			}
			cout << "Данные успешно прочитаны!" << endl;
		}
		else cout << "Файл пуст!" << endl;
		ar.Close();
		fin.Close();

		
	}
	else cout << "Не удалось открыть файл!" << endl;
	

	
	//cout << "Введите название файла для чтения: ";
	//cin.ignore();
	//getline(cin, FileName);
	//ifstream InData;
	//InData.open(FileName);
	//
	//if (InData.is_open())
	//{
	//	
	//	InData >> CustomersAmount;
	//	for (int i = 0; i < CustomersAmount; i++)
	//	{
	//		YudinCustomer Customer;
	//		InData >> Customer;
	//		YudinCustomer* Visitor = new YudinCustomer;
	//		//Customer.ReadFile(InData);
	//		*Visitor = Customer;
	//		Visitors.push_back(Visitor);
	//		Visitor->ShowData();
	//	}
//
	//	InData.close();
	//
	//
	//}
	//else cout << "Не удалось открыть файл!" << endl;
}

void YudinShop::FileSave()
{
	string FileName;

	cout << "Введите название файла для сохранения: ";
	cin >> FileName;

	CString cstrFileName;
	cstrFileName = FileName.c_str();
	CFile fout;
	
	if (fout.Open(cstrFileName, CFile::modeCreate | CFile::modeWrite))
	{
		if (Visitors.size() > 0)
		{
			CArchive ar(&fout, CArchive::store);

			ar << (int)Visitors.size();

			for (auto& Visitor : Visitors)
			{
				ar << Visitor.get();
			}
			ar.Close();
			fout.Close();
			cout << "Файл успешено сохранен!" << endl;
		}
		else cout << "Список покупателей пуст!" << endl;
	}
	
}

void YudinShop::ClearCustomersList()
{
	/*for (auto& Visitor : Visitors)
	{
		delete &Visitor;
	}*/
	Visitors.clear();
	cout << "Список покупателей очищен!" << endl;
}