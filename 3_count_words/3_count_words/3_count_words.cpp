// 3_count_words.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AddToMap.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void EnterStrings(map<string, int> &mapWords)
{
	string strInput;

	do
	{
		strInput.clear();
		getline(cin, strInput);
		
		if (!strInput.empty())
		{
			AddToMap(mapWords, strInput);
		}

	} while (!strInput.empty());
}

void PrintResult(map<string, int> const &mapWords)
{
	for (auto elem : mapWords)
	{
		cout << elem.first << " : ";
		cout << elem.second << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	map<string, int> mapWords;
	EnterStrings(mapWords);
	PrintResult(mapWords);
	return 0;
}

