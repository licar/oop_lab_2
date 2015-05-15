#include "stdafx.h"
#include "Filter.h"

CFilter::CFilter(string const &fileWithIllegalsName ,string &strForFilter)
{
	m_separators.insert(' ');
	m_separators.insert('\n');
	m_separators.insert('\0');
	m_separators.insert('\t');
	m_separators.insert('[');
	m_separators.insert(']');
	m_separators.insert('(');
	m_separators.insert(')');
	m_separators.insert('.');
	m_separators.insert(',');
	m_separators.insert(':');
	m_separators.insert(';');

	ReadIllegalWords(fileWithIllegalsName);
	RemoveIllegalWords(strForFilter);
}

CFilter::~CFilter()
{
}

set<string> CFilter::GetIllegaWords() const
{
	return m_illegalWords;
}

string ToLowRegister(string const &word)
{
	string wordInLowReg;

	for (auto character : word)
	{
		wordInLowReg.push_back(tolower(character));
	}
	return wordInLowReg;
}

bool CFilter::ReadIllegalWords(string const &fileName)
{
	ifstream fileInput(fileName);
	
	if (!fileInput)
	{
		return false;
	}

	while (!fileInput.eof())
	{
		string illegaWord;
		fileInput >> illegaWord;
		m_illegalWords.insert(illegaWord);
		illegaWord.clear();
	}

	fileInput.close();
	return true;
}

bool CFilter::IsWordIllegal(string const &word) const
{
	string wordInLowCase = ToLowRegister(word);

	if (m_illegalWords.find(wordInLowCase) == m_illegalWords.end())
	{
		return false;
	}
	return true;
}

string CFilter::RemoveIllegalWords(
	string const &strWithIllegalWords) const
{
	string strWithoutIllegalWords;
	string buffer;
	bool isWord = false;

	for (auto character : strWithIllegalWords)
	{
		if (m_separators.find(character) == m_separators.end())
		{
			if (!isWord)
			{
				isWord = true;
			}
			buffer.push_back(character);
			continue;
		}
		if (isWord)
		{
			if is
		}
		
	}
	return strWithIllegalWords;
}