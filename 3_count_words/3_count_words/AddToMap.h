#pragma once
#include "stdafx.h"
#include <map>
#include <string>

using namespace std;

void ToLowRegister(string &strBuf);
void IfIsWord(map<string, int> &mapWords, string &strBuf, bool &IsWord);
void AddToMap(map<string, int> &mapWords, string &strInput);