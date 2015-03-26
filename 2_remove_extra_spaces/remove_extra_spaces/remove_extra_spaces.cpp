#pragma once
#include "stdafx.h"
#include "iostream"
#include "string"
#include "remove_extra_spaces.h"

using namespace std;

string RemoveExtraSpaces(string const &arg)
{
	char charBuf;
	string strResult;
	enum position{ start, center };
	bool WriteBuf = false;

	position positionOfCursor = start;

	for (auto charSign : arg)
	{
		switch (positionOfCursor)
		{
		case start:
			if (charSign != ' ')
			{
				strResult.push_back(charSign);
				positionOfCursor = center;
			}
			break;
		case center:
			if (charSign != ' ')
			{
				if (WriteBuf)
				{
					strResult.push_back(charBuf);
					WriteBuf = false;
				}
				strResult.push_back(charSign);
			}
			else
			{
				charBuf = charSign;
				WriteBuf = true;
			}
			break;
		}
	}
	return strResult;
}