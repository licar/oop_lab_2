#pragma once

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <set> 
#include <vector>
#include <memory>
#include <iterator>
#include <math.h>

using namespace std;

void PutPrimeNumbersToSet(vector<bool> const &vectNumbers,
	set<int> &setPrimeNumbers)
{
	for (size_t i = 2; i < vectNumbers.size(); ++i)
	{
		if (vectNumbers.at(i))
		{
			setPrimeNumbers.insert(i);
		}
	}
}

void FindPrimeThroughSieveOfEratosthenes(
	vector<bool> &vectNumbers, int upperBound)
{
	for (size_t i = 2; i <= ceil(sqrt(upperBound)); ++i)
	{
		if (vectNumbers.at(i))
		{
			for (size_t j = pow(i, 2); j <= upperBound; j += i)
			{
				vectNumbers.at(j) = false;
			}
		}
	}
}

set<int>GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> vectNumbers(upperBound + 1, true);
	set<int> setPrimeNumbers;
	
	FindPrimeThroughSieveOfEratosthenes(vectNumbers, upperBound);
	PutPrimeNumbersToSet(vectNumbers, setPrimeNumbers);

	return setPrimeNumbers;
}
