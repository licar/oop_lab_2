// tests_filter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task7_filter/Filter.h"

BOOST_AUTO_TEST_CASE(CanLoadIllegalWords)
{
	CFilter filter;

	BOOST_CHECK(filter.ReadIllegalWords("input.txt"));
	
	set<string> illegalWords;
	illegalWords.insert("bad");
	illegalWords.insert("sad");
	illegalWords.insert("sorrow");

	set<string> illegals = filter.GetIllegaWords();
	
	for (auto word : illegalWords)
	{
		BOOST_CHECK(illegals.find(word) != illegals.end());
	}
}

BOOST_AUTO_TEST_CASE(CanReturnWordInLowReg)
{
	BOOST_CHECK_EQUAL(ToLowRegister("WORLD"), "world");
}

BOOST_AUTO_TEST_CASE(CanFindIllegalWord)
{
	CFilter filter;
	BOOST_CHECK(filter.IsWordIllegal("sad"));
}

