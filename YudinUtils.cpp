#include "YudinUtils.h"
#include "pch.h"

void cin_clear(string title) {
    cin.clear();
    cin.ignore(32767, '\n');
    cout << "\nError! " << title;
}

string to_str(wstring cstr) {
    string str(cstr.begin(), cstr.end());
    return str;
}