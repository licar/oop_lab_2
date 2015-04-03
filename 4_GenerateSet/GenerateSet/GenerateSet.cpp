// GenerateSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "GeneratePrimeNumbers.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int MAX_UPPER_BOUND = 100000000;
	const int MIN_UPPER_BOUND = 0;

	int upperBound;
	cout << "upper bound : ";
	cin >> upperBound;

	if (upperBound > MAX_UPPER_BOUND ||
		upperBound < MIN_UPPER_BOUND)
	{
		cout << "Uncorrect value of upper bound";
		return 1;
	}

	set<int> setPrimeNumber = GeneratePrimeNumbersSet(upperBound);
	for_each(setPrimeNumber.begin(), setPrimeNumber.end(), [](int primeNumber){
		cout << primeNumber << endl;
	});

	return 0;
}

