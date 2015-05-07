#include "stdafx.h"
#include "Filter.h"

CFilter::CFilter()
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

bool CFilter::IsWordIllegal(string const &word)
{
	string wordInLowReg = ToLowRegister(word);

	if (m_separators.find(wordInLowReg) != m_separators.end())
	{
		return false;
	}
	return true;
}

/*string CFilter::RemoveIllegalWords(
	string const &strWithIllegalWords) const
{
	string strWithoutIllegalWords;
	string buffer;
	bool isWord;

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
			if (!IsWordIllegal(buffer))
			{
				strWithoutIllegalWords += buffer;
				strWithoutIllegalWords.push_back(character);
				isWord = false;
				continue;
			}
		}
		strWithoutIllegalWords.push_back(character);
	}
}*/