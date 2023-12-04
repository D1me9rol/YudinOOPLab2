#include "YudinCustomer.h"
#include "pch.h"

using namespace std;

IMPLEMENT_SERIAL(YudinCustomer, CObject, 0);

YudinCustomer::YudinCustomer()
{
	name = "";
	age = -1;
	avg_check = -1.0;
}

void YudinCustomer::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name << age << avg_check;
	}
	else
	{
		ar >> name >> age >> avg_check;
	}
}


CString YudinCustomer::GetName()
{
	return name;
}

int YudinCustomer::GetAge()
{
	return age;
}

double YudinCustomer::GetAvg_Check()
{
	return avg_check;
}



void YudinCustomer::EnterData()
{
	string CName;
	
	cout << "������� ���: ";
	cin.ignore();
	getline(cin, CName);

	cout << "������� �������: ";
	while (!(cin >> age) || (age < 0))
		cin_clear("������� ����� ������ 0\n");

	//cin.ignore();
	cout << "������� ������� �������� ����: ";
	while (!(cin >> avg_check) || (avg_check < 0))
		cin_clear("������� ����� ������ 0\n");

	this->name = CName.c_str();
	//this->age = CAge;
	//this->avg_check = CAvg_check;
}

void YudinCustomer::ShowData()
{
	cout << "\t���: " << to_str(this->name.GetString()) << "\t�������: " << this->age << "\t������� ���: " << this->avg_check << endl;
}