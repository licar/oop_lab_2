#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>

using namespace std;


void ProcessVector(std::vector<double> & numbers)
{
	auto IsPositive = [](double number){return number > 0; };

	size_t numberOfPositives = 0;
	auto sumOfPositives = accumulate(
		numbers.begin(), numbers.end(), 0.0, 
		[&numberOfPositives](double acc, double current) {
			if (current > 0.0)
			{
				++numberOfPositives;
				return acc + current;
			}
		return acc;
	});

	double avg = (numberOfPositives > 0) ? sumOfPositives / numberOfPositives : 0.0;

	if (avg != 0.0)
	{
		transform(numbers.begin(), numbers.end(), numbers.begin(),
			[avg](double number){return number + avg;});
	}
}