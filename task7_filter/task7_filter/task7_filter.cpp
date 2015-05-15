// task7_filter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Filter.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "i bad guy sorrow";
	string file = "input.txt";

	CFilter filter(file, str);
	return 0;
}

