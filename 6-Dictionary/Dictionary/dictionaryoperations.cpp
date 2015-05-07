#pragma once
#include "stdafx.h"
#include <map>
#include "dictionaryoperations.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void ToLowRegister(string const &strEng, string &strEngInLowReg)
{
	for (auto character : strEng)
	{
		strEngInLowReg.push_back(tolower(character));
	}
}

void GetTranslate(string const &strEng, string &strRus)
{
	cout << "Неизвестное слово " << strEng
		<< " Введите перевод или пустую строку для отказа. " << endl;

	cout << "перевод :";
	cin.ignore(256, '\n');
	getline(cin, strRus);
}

bool AddToDictionary(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend, string const &strEng)
{
	string strRus;
	GetTranslate(strEng, strRus);

	if (strRus.empty())
	{
		cout << "Слово " << strEng
			<< " было проигнорировано" << endl;
		return false;
	}

	dictWithSessionAppend[strEng] = strRus;
	dictionary[strEng] = strRus;

	cout << "Слово " << strEng
		<< " сохранено, как " << strRus << endl;
	return true;
}

void RemoveBrackets(string const &englishWithBrackets,
	string &english)
{
	const char BRACKET_RIGHT = ']';
	const char BRACKET_LEFT = '[';

	for (auto character : englishWithBrackets)
	{
		if (character != BRACKET_LEFT &&
			character != BRACKET_RIGHT)
		{
			english.push_back(character);
		}
	}
}

bool DictionaryLoaded(string const &fileName,
	map<string, string> &dictionary)
{
	ifstream fileInput(fileName);

	if (!fileInput)
	{
		return false;
	}

	string englishWithBrackets;
	string english;
	string russian;

	while (!fileInput.eof())
	{
		fileInput >> englishWithBrackets;
		RemoveBrackets(englishWithBrackets, english);
		fileInput >> russian;
		dictionary[english] = russian;
		english.clear();
		russian.clear();
	}

	fileInput.close();
	return true;
}

void WriteSessionChangesToFile(string const &fileName,
	map<string, string> const &dictWithSessionAppend)
{
	ofstream fileOutput(fileName, ios::app);
	
	if (!fileOutput)
	{
		cout << "Changes will not save becouse can't open file";
		return;
	}
	
	for (auto translation : dictWithSessionAppend)
	{
		fileOutput << '[' << translation.first.c_str() <<
			']' << ' '<< translation.second.c_str() << '\n';
	}
	fileOutput.close();
}

void PrintTranslation(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend, string const &strEng)
{
	string strEngInLowReg;
	ToLowRegister(strEng, strEngInLowReg);

	if (dictionary.find(strEngInLowReg) != dictionary.end())
	{
		cout << dictionary[strEngInLowReg] << endl;
	}
	else
	{
		AddToDictionary(dictionary,
			dictWithSessionAppend, strEngInLowReg);
	}
}

bool SaveChanges()
{
	cout << "would you like to save chanes Y/any : ";
	char isSave;
	cin >> isSave;
	
	if (isSave)
	{
		return true;
	}
	return false;
}

void EnterWord(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend)
{
	string strEng;
	const string EXIT_EXPRESSION = "...";

	do
	{
		cout << "Enter word : ";
		cin >> strEng;

		if (strEng != EXIT_EXPRESSION)
		{
			PrintTranslation(dictionary,
				dictWithSessionAppend, strEng);
		}
	} while (strEng != EXIT_EXPRESSION);
}