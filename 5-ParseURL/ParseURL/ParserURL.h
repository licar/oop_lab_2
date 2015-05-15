#pragma once
#include <string>

using namespace std;

class CParserURL
{
public:

	enum Protocol
	{
		HTTP = 80,
		HTTPS = 443,
		FTP = 21
	};

	CParserURL(string const &url);
	~CParserURL();

	string GetURL() const;
	string GetProtocol() const;
	int GetPort() const;
	string GetHost() const;
	string GetDocument() const;

	bool IsEmpty() const;

	bool SetPort(string const &port);
	bool SetHost(string const &host);
	void SetDocument(string const &document);
	bool SetProtocol(string const &protocol);

private:

	bool Parse();

	enum PartURL
	{
		protocolURL,
		hostURL,
		portURL,
		documentURL
	};

	string m_url;
	string m_protocol;
	int m_port;
	string m_host;
	string m_document;
};

string ToLowRegister(string const &str);