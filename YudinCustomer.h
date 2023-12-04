#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "pch.h"
#include "YudinUtils.h"

//using namespace std;

class YudinCustomer : public CObject {
private:
	CString name;
	int age;
	double avg_check;

public:

	DECLARE_SERIAL(YudinCustomer)
	
	virtual void Serialize(CArchive& ar);
	virtual void EnterData();
	virtual void ShowData();

	YudinCustomer();
	virtual ~YudinCustomer() {};

	CString GetName();
	int GetAge();
	double GetAvg_Check();

};


