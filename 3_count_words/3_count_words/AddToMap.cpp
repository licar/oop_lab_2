#pragma once
#include "stdafx.h"
#include <map>
#include <string>
#include <iterator>
#include <cctype>    

using namespace std;

void ToLowRegister(string &strBuf)
{
	string::iterator it = strBuf.begin();
	for (; it != strBuf.end(); ++it)
	{
		*it = tolower(*it);
	}
}

void AddToMapOrIncExistValue(map<string, int> &mapWords, string &strBuf, bool &IsWord)
{
	ToLowRegister(strBuf);
	if (mapWords.find(strBuf) != mapWords.end())
	{
		++mapWords[strBuf];
	}
	else
	{
		mapWords[strBuf] = 1;
	}
	strBuf.clear();
	IsWord = false;
}

void AddToMap(map<string, int> &mapWords, string &strInput)
{
	string strBuf;
	bool IsWord = false;

	for (auto charSign : strInput)
	{
		if (charSign != ' ' && charSign != ',' && charSign != '.' &&
			charSign != '\n' )
		{
			strBuf.push_back(charSign);
			IsWord = true;
		}
		else
		{
			if (IsWord)
			{
				AddToMapOrIncExistValue(mapWords, strBuf, IsWord);
			}
		}
	}

	if (IsWord)
	{
		AddToMapOrIncExistValue(mapWords, strBuf, IsWord);
	}
}