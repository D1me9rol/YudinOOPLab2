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
	
	cout << "Введите имя: ";
	cin.ignore();
	getline(cin, CName);

	cout << "Введите возраст: ";
	while (!(cin >> age) || (age < 0))
		cin_clear("Введите число больше 0\n");

	//cin.ignore();
	cout << "Введите среднее значение чека: ";
	while (!(cin >> avg_check) || (avg_check < 0))
		cin_clear("Введите число больше 0\n");

	this->name = CName.c_str();
	//this->age = CAge;
	//this->avg_check = CAvg_check;
}

void YudinCustomer::ShowData()
{
	cout << "\tИмя: " << to_str(this->name.GetString()) << "\tВозраст: " << this->age << "\tСредний чек: " << this->avg_check << endl;
}