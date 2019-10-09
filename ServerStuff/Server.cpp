// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <WinSock2.h>
#include <iostream>

#define MAXPENDINGCON 8

using namespace std;

int main()
{
	SOCKET server;
	SOCKADDR_IN server_addr, client_addr;	// Server address, client address
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != NO_ERROR)
	{
		cout << "WSAStartup failed!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Started successfully" << endl;
	}

	
	if ((server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		cout << "Socket failed" << endl;
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(3001);
	if (bind(server, (struct sockaddr*) &server_addr, sizeof(server_addr)) == SOCKET_ERROR)
	{
		cout << "Bind failed" << endl;
		exit(EXIT_FAILURE);
	}

	if (listen(server, MAXPENDINGCON) == SOCKET_ERROR)
	{
		cout << "Listen failed!" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "SERVER STARTED!" << endl;
	while (true)
	{
		SOCKET client;
		int clientLenght = sizeof()
		if ((client = accept(server, (struct sockaddr*) &client_addr, %clientLenght)) == INVALID_SOCKET)
        {
            cout << "Listen failed" << endl;
            exit(EXIT_FAILURE);
        }
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
