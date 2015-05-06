#include "stdafx.h"
#include "ParserURL.h"


CParserURL::CParserURL(string const &url)
	:m_url(url)
{
}

CParserURL::~CParserURL()
{
}

bool CParserURL::IsEmpty() const
{
	return m_url.empty();
}

string CParserURL::GetURL() const
{
	return m_url;
}

int CParserURL::GetPort() const
{
	return m_port;
}

string CParserURL::GetHost() const
{
	return m_host;
}

int CParserURL::GetProtocol() const
{
	return m_protocol;
}


string CParserURL::GetDocument() const
{
	return m_document;
}

string ToLowRegister(string const &str)
{
	string strWithLowChars;
	for (auto character : str)
	{
		strWithLowChars.push_back(tolower(character));
	}
	return strWithLowChars;
}

bool CParserURL::SetProtocol(string const &protocol)
{
	string strProtocol = ToLowRegister(protocol);

	if (strProtocol == "http")
	{
		m_protocol = HTTP;
	}
	else if (strProtocol == "https")
	{
		m_protocol = HTTPS;
	}
	else if (strProtocol == "ftp")
	{
		m_protocol = FTP;
	}
	else
	{
		return false;
	}
	return true;
}

bool CParserURL::SetHost(string const &host)
{
	const char DOT = '.';
	const int NORM_AMOUNT_W = 3;
	int countChar = 0;

	for (size_t i = 0; i != host.length(); ++i)
	{
		if (host[i] == DOT && i > 0 &&
			i < (host.length() - 1))
		{
			m_host = host;
			return true;
		}
	}
	return false;
}

bool CParserURL::SetPort(string const &port)
{
	const int MAX_PORT = 65535;
	const int MIN_PORT = 1;
	int portBuff = stoi(port);

	if (portBuff > MAX_PORT || portBuff < MIN_PORT)
	{
		return false;
	}

	m_port = portBuff;
	return true;
}

void CParserURL::SetDocument(string const &document)
{
	m_document = document;
}

bool CParserURL::Parse()
{
	const char SLASH = '/';
	const char DOUBLE_DOT = ':';
	const char EMPTY_CHAR = ' ';

	if (IsEmpty())
	{
		return false;
	}

	PartURL partURL = protocolURL;
	string buffer;

	for (size_t i = 0; i != m_url.length(); ++i)
	{
		if (m_url[i] != SLASH && m_url[i] != DOUBLE_DOT)
		{
			if (i < m_url.length() - 1)
			{
				buffer.push_back(m_url[i]);
				continue;
			}
			else
			{
				if (m_url[i] != SLASH)
				{
					buffer.push_back(m_url[i]);
				}
			}
		}

		switch (partURL)
		{
		case protocolURL:
			if (!SetProtocol(buffer))
			{
				return false;
			}

			if (m_url[i] != DOUBLE_DOT ||
				i + 1 > m_url.length() || m_url[i + 1] != SLASH ||
				i + 2 > m_url.length() || m_url[i + 2] != SLASH)
			{
				return false;
			}
			i += 2;
			partURL = hostURL;
			break;
		case hostURL:	
			if (!SetHost(buffer))
			{
				return false;
			}

			switch (m_url[i])
			{
			case DOUBLE_DOT:
				partURL = portURL;
				break;
			case SLASH:
				m_port = m_protocol;
				partURL = documentURL;
				break;
			default:
				m_port = m_protocol;
				return true;
				break;
			}
			break;
		case portURL:
			if (!SetPort(buffer))
			{
				return false;
			}
			partURL = documentURL;
			break;
		case documentURL:
			SetDocument(buffer);
			break;
		};
		buffer.clear();
	}
	return true;
}