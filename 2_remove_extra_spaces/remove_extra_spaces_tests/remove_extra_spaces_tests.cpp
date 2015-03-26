// remove_extra_spaces_tests.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include "../remove_extra_spaces/remove_extra_spaces.h"

using namespace std;

bool StringsAreEqual(string const &first, string const& second)
{
	return first == second;
}

BOOST_AUTO_TEST_CASE(EmptyStringProducesEmptyString)
{ 
	string strResult = RemoveExtraSpaces("");
	BOOST_CHECK(strResult.empty());
}

BOOST_AUTO_TEST_CASE(StringWithSpaceInStartProducesEmptyString)
{
	string strResult = RemoveExtraSpaces(" ");
	BOOST_CHECK(strResult.empty());
}

BOOST_AUTO_TEST_CASE(StringWithTwoSpacesProducesStringWithOneSpace)
{
	string strResult = RemoveExtraSpaces("world  day");
	BOOST_CHECK(StringsAreEqual("world day", strResult));
}

BOOST_AUTO_TEST_CASE(StringWithSpaceInEndProducesStringWithoutSpaceInTheEnd)
{
	string strResult = RemoveExtraSpaces("world  ");
	BOOST_CHECK(StringsAreEqual("world", strResult));
}

BOOST_AUTO_TEST_CASE(StringWithExtraSpacesProducesStringWithoutExtraSpaces)
{
	string strResult = RemoveExtraSpaces("    world  have   a lot of misteries ");
	BOOST_CHECK(StringsAreEqual("world have a lot of misteries", strResult));
}
