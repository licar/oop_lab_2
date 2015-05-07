// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dictionaryoperations.h" 

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	string fileName;
	cout << "Enter file name : ";
	cin >> fileName;

	map<string, string> dictionary;
	map<string, string> dictWithSessionAppend;

	if (!DictionaryLoaded(fileName, dictionary))
	{
		cout << "dictionary didn't load";
		return 1;
	}

	EnterWord(dictionary, dictWithSessionAppend);

	if (SaveChanges())
	{
		WriteSessionChangesToFile(fileName,
			dictWithSessionAppend);
	}

	return 0;
}

