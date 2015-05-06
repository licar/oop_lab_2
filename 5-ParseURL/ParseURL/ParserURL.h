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

	enum PartURL
	{
		protocolURL,
		hostURL,
		portURL,
		documentURL
	};

	CParserURL(string const &url);
	~CParserURL();

	string GetURL() const;
	int GetProtocol() const;
	int GetPort() const;
	string GetHost() const;
	string GetDocument() const;

	bool Parse();
	bool IsEmpty() const;

	bool SetPort(string const &port);
	bool SetHost(string const &host);
	void SetDocument(string const &document);
	bool SetProtocol(string const &protocol);

private:
	string m_url;
	Protocol m_protocol;
	int m_port;
	string m_host;
	string m_document;
};

string ToLowRegister(string const &str);