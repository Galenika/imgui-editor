#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "../includes.h"

enum RequestFlags
{
	REQUEST_GET,
	REQUEST_POST,
	RETURN_HEADERS,
	RETURN_CONTENT
};

class CRequests
{
public:
	std::string MakeRequest(std::string szHost, std::string szRequest, DWORD dwFlags);
	std::string GetDomainIP(std::string szDomain);
};

extern CRequests* g_Requests;