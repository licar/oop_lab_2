// GenerateSet_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../GenerateSet/GeneratePrimeNumbers.h"
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

BOOST_AUTO_TEST_CASE(PutOneAndGenerateEmptySet)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(1).empty());
}

BOOST_AUTO_TEST_CASE(PutTwoAndGenerateSetWithOneNumber)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(2).size() == 1);
}

BOOST_AUTO_TEST_CASE(PutTenAndGenerateSetWithFourNumbers)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(10).size() == 4);
}

BOOST_AUTO_TEST_CASE(PutThousandAndGenerateSetWithFourNumbers)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(1000).size() == 168);
}



