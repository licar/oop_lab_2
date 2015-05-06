#pragma once
#include "stdafx.h"
#include <iostream>
#include "ParserURL.h" 

using namespace std;

void PrintToOutstream(CParserURL const &parser)
{
	cout << parser.GetURL() << endl <<
		"HOST:" << parser.GetHost() << endl <<
		"PORT:" << parser.GetPort() << endl <<
		"DOC:" << parser.GetDocument() << endl;
}

int main()
{
	cout << "Enter URL\n:";
	string url;
	cin >> url;
	CParserURL parser(url);

	if (parser.Parse())
	{
		PrintToOutstream(parser);
	}

	return 0;
}