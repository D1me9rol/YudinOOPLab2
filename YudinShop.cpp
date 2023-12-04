#include "YudinShop.h"
#include "pch.h"
#include <typeinfo>
using namespace std;

void YudinShop::AddCustomer()
{
	/*string name;
	int age;
	double avg_check;

	cout << "������� ���: ";
	cin.ignore();
	getline(cin, name);

	cout << "������� �������: ";
	cin >> age;

	cin.ignore();
	cout << "������� ������� �������� ����: ";
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
	else cout << "������ ����������� ����!" << endl;
	cout << "------------------------------" << endl;
}

void YudinShop::FileRead()
{
	//Visitors.clear();
	//int CustomersAmount;
	string FileName;
	
	cout << "������� �������� ����� ��� ������: " << endl;
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
			cout << "������ ������� ���������!" << endl;
		}
		else cout << "���� ����!" << endl;
		ar.Close();
		fin.Close();

		
	}
	else cout << "�� ������� ������� ����!" << endl;
	

	
	//cout << "������� �������� ����� ��� ������: ";
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
	//else cout << "�� ������� ������� ����!" << endl;
}

void YudinShop::FileSave()
{
	string FileName;

	cout << "������� �������� ����� ��� ����������: ";
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
			cout << "���� �������� ��������!" << endl;
		}
		else cout << "������ ����������� ����!" << endl;
	}
	
}

void YudinShop::ClearCustomersList()
{
	/*for (auto& Visitor : Visitors)
	{
		delete &Visitor;
	}*/
	Visitors.clear();
	cout << "������ ����������� ������!" << endl;
}