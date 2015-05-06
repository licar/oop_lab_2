#pragma once
#include "stdafx.h"
#include <map>
#include "dictionaryoperations.h"
#include <string>
#include <iostream>

using namespace std;

void ToLowRegister(string const &strEng, string &strEngInLowReg)
{
	for (auto character : strEng)
	{
		strEngInLowReg.push_back(tolower(character));
	}
}

void AddToDictionary(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend, string const &strEng)
{
	
	string strRus;

	cout << "Неизвестное слово" << strEng 
		<< " Введите перевод или пустую строку для отказа. " << endl;

	cout << "перевод :";
	cin.ignore(256, '\n');
	getline(cin, strRus);

	if (strRus.empty())
	{
		cout << "Слово " << strEng
			<< " было проигнорировано" << endl;
		return;
	}

	dictWithSessionAppend[strEng] = strRus;
	dictionary[strEng] = strRus;

	cout << "Слово " << strEng
		<< " сохранено, как " << strRus << endl;
}

bool DictionaryLoaded(string const fileName,
	map<string, string> &dictionary)
{
	char character;
	string bufferRus;
	string bufferEng;
	bool fillEngBuffer = true;

	FILE *fileDict = fopen(fileName.c_str(), "r");
	
	if (!fileDict)
	{
		cout << "Can't open file";
		return false;
	}
	
	while (!feof(fileDict))
	{
		character = getc(fileDict);
		if (feof(fileDict) || (character == '\n'))
		{
			dictionary[bufferEng] = bufferRus;
			fillEngBuffer = true;

			bufferRus.clear();
			bufferEng.clear();
		}
		else if (character == ' ')
		{
			fillEngBuffer = false;
		}
		else if (character == '[' ||
			character == ']')
		{
			continue;
		}
		else
		{
			if (fillEngBuffer)
			{
				bufferEng.push_back(character);
			}
			else
			{
				bufferRus.push_back(character);
			}
		}
	}

	fclose(fileDict);
	return true;
}

void WriteSessionChangesToFile(string const &dictName,
	map<string, string> const &dictWithSessionAppend)
{
	FILE *fileDict = fopen(dictName.c_str(), "a");
	
	if (!fileDict)
	{
		cout << "Changes will not save becouse can't open file";
		return;
	}
	
	for (auto translation : dictWithSessionAppend)
	{
		fputc('[', fileDict);
		fputs(translation.first.c_str(), fileDict);
		fputc(']', fileDict);
		fputc(' ', fileDict);
		fputs(translation.second.c_str(), fileDict);
		fputc('\n', fileDict);
	}
	fclose(fileDict);
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