#pragma once
#include <map>
#include <string>
#include <iostream>
#pragma warning (disable : 4996)

using namespace std;

void AddToDictionary(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend, string const &strEng);

void PrintTranslation(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend, string const &strEng);

bool DictionaryLoaded(string const fileName,
	map<string, string> &dictionary);

void WriteSessionChangesToFile(string const &dictName,
	map<string, string> const &dictWithSessionAppend);

void EnterWord(map<string, string> &dictionary,
	map<string, string> &dictWithSessionAppend);