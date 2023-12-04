#pragma once
#include "YudinCustomer.h"


class YudinWholesaler : public YudinCustomer
{
private:
	CString CompanyName;
	CString ProductType;
public:

	DECLARE_SERIAL(YudinWholesaler);

	void EnterData();
	void ShowData();

	virtual void Serialize(CArchive& ar);

};

