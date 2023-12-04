#pragma once
#include "YudinWholesaler.h"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class YudinShop
{
private:
	vector<shared_ptr<YudinCustomer>> Visitors;
	
public:
	

	void AddCustomer();
	void AddWholeSaler();
	void ShowCustomersList();
	void FileRead();
	void FileSave();
	void ClearCustomersList();


};

