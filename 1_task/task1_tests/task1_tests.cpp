// task1_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyVectorProducesEmptyVector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(VectorWithoutPositivesDoesntChangeContent)
{
	vector<double> numbers = { -4, 0, -3 };
	auto copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

BOOST_AUTO_TEST_CASE(VectorWithOnePositiveElement)
{
	vector<double> numbers = { -1, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 2, 6 }));
}

BOOST_AUTO_TEST_CASE(VectorWithSeveralPositiveElements)
{
	vector<double> numbers = { -1, 1, 2, 3};
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { (-1+2), (1+2), (2+2), (3+2) }));
}