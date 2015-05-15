// Dictionary_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Dictionary/dictionaryoperations.h"

BOOST_AUTO_TEST_CASE(CanLoadDictionary)
{
	map<string, string> dictionary;
	map<string, string> dictSessionChanges;

	BOOST_CHECK(DictionaryLoaded("input.txt", dictionary));
	BOOST_CHECK(!DictionaryLoaded("input1.txt", dictionary));
}

BOOST_AUTO_TEST_CASE(ToLowCase)
{
	string wordInHighCase = "WOrd";
	BOOST_CHECK_EQUAL("word", ToLowRegister(wordInHighCase));
}
