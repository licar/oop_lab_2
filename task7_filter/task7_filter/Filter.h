#pragma once
#include <string>
#include <set>
#include <fstream>

using namespace std;

class CFilter
{
public:
	CFilter(string const &fileWithIllegalsName, string &strForFilter);
	~CFilter();

	bool ReadIllegalWords(string const &fileName);
	set<string> GetIllegaWords() const;
	
	string RemoveIllegalWords(
		string const &strWithIllegalWords) const;
	
	bool IsWordIllegal(string const &word) const;

private:
	set<string> m_illegalWords;
	set<char> m_separators;
};

string ToLowRegister(string const &word);
