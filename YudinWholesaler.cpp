#include "YudinWholesaler.h"
#include "pch.h"
using namespace std;

IMPLEMENT_SERIAL(YudinWholesaler, YudinCustomer, VERSIONABLE_SCHEMA | 0);


void YudinWholesaler::EnterData()
{
	YudinCustomer::EnterData();

	string CCompanyName, CProductType;

	cout << "Название компании: ";
	cin.ignore();
	getline(cin, CCompanyName);

	cout << "Введите тип продукта: ";
	getline(cin, CProductType);

	this->CompanyName = CCompanyName.c_str();
	this->ProductType = CProductType.c_str();

	

}

void YudinWholesaler::ShowData()
{
	//cout << "\tИмя: " << name << "\tВозраст: " << age << "\tСредний чек: " << avg_check << "\tНазвание компании: " << CompanyName << "\tТип продукта: " << ProductType << endl;
	YudinCustomer::ShowData();
	cout << "Название компании: " << to_str(this->CompanyName.GetString()) << "\tТип продукта: " << to_str(this->ProductType.GetString());
	
}

void YudinWholesaler::Serialize(CArchive& ar)
{
	YudinCustomer::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << CompanyName << ProductType;
	}
	else
	{
		ar >> CompanyName >> ProductType;
	}
}