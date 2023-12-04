#include "YudinWholesaler.h"
#include "pch.h"
using namespace std;

IMPLEMENT_SERIAL(YudinWholesaler, YudinCustomer, VERSIONABLE_SCHEMA | 0);


void YudinWholesaler::EnterData()
{
	YudinCustomer::EnterData();

	string CCompanyName, CProductType;

	cout << "�������� ��������: ";
	cin.ignore();
	getline(cin, CCompanyName);

	cout << "������� ��� ��������: ";
	getline(cin, CProductType);

	this->CompanyName = CCompanyName.c_str();
	this->ProductType = CProductType.c_str();

	

}

void YudinWholesaler::ShowData()
{
	//cout << "\t���: " << name << "\t�������: " << age << "\t������� ���: " << avg_check << "\t�������� ��������: " << CompanyName << "\t��� ��������: " << ProductType << endl;
	YudinCustomer::ShowData();
	cout << "�������� ��������: " << to_str(this->CompanyName.GetString()) << "\t��� ��������: " << to_str(this->ProductType.GetString());
	
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