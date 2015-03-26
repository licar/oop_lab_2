// count_words_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>
#include "../3_count_words/AddToMap.h"

using namespace std;

BOOST_AUTO_TEST_CASE(EmptyMapProduceEmptyMap)
{
	map<string, int> mapWords;
	string strEmpty;
	AddToMap(mapWords, strEmpty);
	BOOST_CHECK(mapWords.empty());
}

BOOST_AUTO_TEST_CASE(StringWithSpacesProduceEmptyMap)
{
	map<string, int> mapWords;
	string strSpaces = "   ";
	AddToMap(mapWords, strSpaces);
	BOOST_CHECK(mapWords.empty());
}

BOOST_AUTO_TEST_CASE(OneWordProcedureMapWithOneElem)
{
	map<string, int> mapWords;
	string strWord = "live";
	AddToMap(mapWords, strWord);
	BOOST_CHECK(mapWords.find(strWord) != mapWords.end());
}

BOOST_AUTO_TEST_CASE(TwoSameWordProcedureMapWithOneElemWithCountEqual2)
{
	map<string, int> mapWords;
	string strWord = "live";
	string strTwoWords = "live live";
	AddToMap(mapWords, strTwoWords);
	BOOST_CHECK(mapWords.find(strWord) != mapWords.end());
	BOOST_CHECK_EQUAL(mapWords[strWord], 2);
}

BOOST_AUTO_TEST_CASE(TwoDiffWordProcedureMapWithTwoElem)
{
	map<string, int> mapWords;
	string strWordOne = "live";
	string strWordTwo = "alive";
	string strTwoWords = "live alive";
	AddToMap(mapWords, strTwoWords);
	BOOST_CHECK(mapWords.find(strWordOne) != mapWords.end());
	BOOST_CHECK(mapWords.find(strWordTwo) != mapWords.end());
}

BOOST_AUTO_TEST_CASE(TwoSameWordsWithDiffRegProcedureMapWithOneElem)
{
	map<string, int> mapWords;
	string strWord = "live";
	string strTwoWords = "Live liVe";
	AddToMap(mapWords, strTwoWords);
	BOOST_CHECK(mapWords.find(strWord) != mapWords.end());
	BOOST_CHECK_EQUAL(mapWords[strWord], 2);
}




