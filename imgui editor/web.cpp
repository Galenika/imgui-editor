#include "web.h"


std::string CRequests::MakeRequest(std::string szHost, std::string szRequest, DWORD dwFlags)
{
	std::string szHeaders = ("Content-Type: application/x-www-form-urlencoded\r\n");
	char sHeaders[50];
	sprintf(sHeaders, "%s", szHeaders.c_str());
	char sPageContent[1024];
	DWORD dwRead;
	memset(sPageContent, 0, sizeof(sPageContent));
	HINTERNET hInet = InternetOpenA(("Mozilla/4.0 (compatible; MSIE 6.0b; Windows NT 5.0; .NET CLR 1.0.2914)"), INTERNET_OPEN_TYPE_PRECONFIG, "", "", 0);
	HINTERNET hSession = InternetConnectA(hInet, szHost.c_str(), 80, "", "", INTERNET_SERVICE_HTTP, 0, 1u);
	HINTERNET hRequest = HttpOpenRequestA(hSession, (dwFlags & REQUEST_GET) ? ("GET") : ((dwFlags & REQUEST_POST) ? ("POST") : ("GET")), szRequest.c_str(), NULL, szHost.c_str(), 0, 0, 1);
	HttpSendRequestA(hRequest, sHeaders, sizeof(sHeaders) - 1, NULL, NULL);
	InternetReadFile(hRequest, &sPageContent, sizeof(sPageContent), &dwRead);
	InternetCloseHandle(hRequest);
	InternetCloseHandle(hSession);
	InternetCloseHandle(hInet);

	return (dwFlags & RETURN_CONTENT) ? std::string(sPageContent) : ((dwFlags & RETURN_HEADERS) ? std::string(sHeaders) : std::string(sPageContent));
}

std::string CRequests::GetDomainIP(std::string szDomain)
{
	WSADATA lpWSAData;
	struct hostent* RemoteHost;
	WSAStartup(MAKEWORD(2, 2), &lpWSAData);
	RemoteHost = gethostbyname(szDomain.c_str());
	return inet_ntoa(*(struct in_addr*)RemoteHost->h_addr_list[0]);
}

CRequests* g_Requests;
