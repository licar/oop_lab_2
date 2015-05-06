// ParseURL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ParseURL/ParserURL.h"

BOOST_AUTO_TEST_CASE(CanSetProtocol)
{
	CParserURL url("");
	BOOST_CHECK(url.SetProtocol("ftp"));
	BOOST_CHECK(url.SetProtocol("http"));
	BOOST_CHECK(url.SetProtocol("https"));
	BOOST_CHECK(!url.SetProtocol("ftpp"));
}

BOOST_AUTO_TEST_CASE(CanSetHost)
{
	CParserURL url("");
	BOOST_CHECK(!url.SetHost(""));
	BOOST_CHECK(url.SetHost("my.ru"));
	BOOST_CHECK(url.SetHost("my.ru.ru"));
	BOOST_CHECK(!url.SetHost("my"));
	BOOST_CHECK(!url.SetHost(".my"));
	BOOST_CHECK(!url.SetHost("my."));
	BOOST_CHECK(!url.SetHost(".my."));
}

BOOST_AUTO_TEST_CASE(CanSetPort)
{
	CParserURL url("");
	BOOST_CHECK(!url.SetPort("0"));
	BOOST_CHECK(!url.SetPort("70000"));
	BOOST_CHECK(url.SetPort("21"));
	BOOST_CHECK(!url.SetPort("-21"));
}

BOOST_AUTO_TEST_CASE(CanCheckIsUrlEmpty)
{
	CParserURL url("");
	BOOST_CHECK(url.IsEmpty());
	CParserURL url1("url");
	BOOST_CHECK(!url1.IsEmpty());
}

BOOST_AUTO_TEST_CASE(CanParceUrl)
{
	{
		CParserURL url1("");
		BOOST_CHECK(!url1.Parse());
	}
	{
		CParserURL url2("https://www.google.com/search");
		BOOST_CHECK(url2.Parse());
		BOOST_CHECK_EQUAL(url2.GetProtocol(), 443);
		BOOST_CHECK_EQUAL(url2.GetHost(), "www.google.com");
		BOOST_CHECK_EQUAL(url2.GetPort(), 443);
		BOOST_CHECK_EQUAL(url2.GetDocument(), "search");
	}
	{
		CParserURL url2("https://www.google.com");
		BOOST_CHECK(url2.Parse());
		BOOST_CHECK_EQUAL(url2.GetProtocol(), 443);
		BOOST_CHECK_EQUAL(url2.GetHost(), "www.google.com");
		BOOST_CHECK_EQUAL(url2.GetPort(), 443);
	}
	{
		CParserURL url2("https://google");
		BOOST_CHECK(!url2.Parse());
	}

}


