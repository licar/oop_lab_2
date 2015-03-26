// string1.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include "iostream"
#include "string"
#include "remove_extra_spaces.h"

using namespace std;

void GetIstream()
{
	string arg;

	do
	{
		cout << "Enter string : ";
		getline(cin, arg);
		string strResult = RemoveExtraSpaces(arg);
		cout << strResult << endl;
	} 
	while (arg.length() != 0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	GetIstream();
	return 0;
}

