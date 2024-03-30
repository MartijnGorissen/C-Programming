#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")
#pragma warning(disable : 4996)


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

      const char* ipAddress = "localhost";
    //const char* ipAddress = "192.168.2.20";

    int temperatuur = 0;
    int tempGrens = 25;
    int luchtvochtigheid = 0;
    int luchtvochtGrens = 50;
    char replyBuffer[DEFAULT_BUFLEN];


        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            printf("WSAStartup failed with error: %d\n", iResult);
            return 1;
        }
        

            ZeroMemory(&hints, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;
            hints.ai_flags = AI_PASSIVE;

       

            // Resolve the server address and port
            iResult = getaddrinfo(ipAddress, DEFAULT_PORT, &hints, &result);
           // iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
            if (iResult != 0) {
                printf("getaddrinfo failed with error: %d\n", iResult);
                WSACleanup();
                return 1;
            }
           
            // Create a SOCKET for the server to listen for client connections.
            ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
            if (ListenSocket == INVALID_SOCKET) {
                printf("socket failed with error: %ld\n", WSAGetLastError());
                freeaddrinfo(result);
                WSACleanup();
                return 1;
            }

            
            // Setup the TCP listening socket
            iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
            if (iResult == SOCKET_ERROR) {
                printf("bind failed with error: %d\n", WSAGetLastError());
                freeaddrinfo(result);
                closesocket(ListenSocket);
                WSACleanup();
                return 1;
            }

        
            freeaddrinfo(result);

            while (1) {                 //server aan houden zodat deze niet steeds opnieuw moet opstarten

                iResult = listen(ListenSocket, SOMAXCONN);
                if (iResult == SOCKET_ERROR) {
                    printf("listen failed with error: %d\n", WSAGetLastError());
                    closesocket(ListenSocket);
                    WSACleanup();
                    return 1;
                }

                // Accept a client socket
                ClientSocket = accept(ListenSocket, NULL, NULL);
                if (ClientSocket == INVALID_SOCKET) {
                    printf("accept failed with error: %d\n", WSAGetLastError());
                    closesocket(ListenSocket);
                    WSACleanup();
                    return 1;
                }



                // Receive until the peer shuts down the connection
                do {

                    iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
                    memset(replyBuffer, 0, sizeof(replyBuffer));
                    if (iResult > 0) {
                        recvbuf[iResult] = '\0';
                        if (sscanf(recvbuf, "temperatuur: %d", &temperatuur) == 1) {                    //checken of het om de temperatuur gaat
                            if (temperatuur > tempGrens) {                  //warmer dan 25c
                                //printf("Het is veel te warm.\nVentilator gaat aan met 1000 RPM.\n");  //printf niet nodig op de server
                                strcpy(replyBuffer, "Het is veel te warm. Ventilator gaat aan met 1000 RPM."); //een reply die naar de client wordt gestuurt. 
                            }
                            else if (temperatuur == tempGrens) {            //25c
                                //printf("Het is een beetje warm.\nVentilator gaat aan met 500 RPM.\n");
                                strcpy(replyBuffer, "Het is een beetje warm. Ventilator gaat aan met 500 RPM.");
                            }
                            else {                                          //kouder dan 25c
                                //printf("Niet warm genoeg voor de ventilator.\nVentilator gaat uit.\n");
                                strcpy(replyBuffer, "Niet warm genoeg voor de ventilator. Ventilator gaat uit.");
                            }
                        }
                        else if (sscanf(recvbuf, "luchtvochtigheid: %d", &luchtvochtigheid) == 1) { //checken of het om de luchtvochtigheid gaat
                            if (luchtvochtigheid > luchtvochtGrens + 10) {          //hoger dan 50+10 
                                //printf("Luchtvochtigheid te hoog. Ramen gaan nu open.\n");
                                strcpy(replyBuffer, "Luchtvochtigheid te hoog. Ramen gaan nu open.");
                            }
                            else if (luchtvochtigheid < luchtvochtGrens - 10) {    //lager dan 50-10
                                //printf("Luchtvochtigheid te laag. Ramen gaan nu open.\n");
                                strcpy(replyBuffer, "Luchtvochtigheid te laag. Ramen gaan nu open.");
                            }
                            else {
                                //printf("Luchtvochtigheid is prima.\n");
                                strcpy(replyBuffer, "Luchtvochtigheid is prima.");
                            }
                        }


                        printf("Ontvangen bericht van de client: %s\n", recvbuf);
                        printf("Bytes received: %d\n", iResult);

                        // Echo the buffer back to the sender
                        //const char* antwoord = "Bericht is ontvangen.";

                        iSendResult = send(ClientSocket, replyBuffer, strlen(replyBuffer), 0);
                        // iSendResult = send(ClientSocket, recvbuf, iResult, 0);
                        printf("Bytes sent: %d\n", iSendResult);
                        if (iSendResult == SOCKET_ERROR) {
                            printf("send failed with error: %d\n", WSAGetLastError());
                            closesocket(ClientSocket);
                            WSACleanup();
                            return 1;
                        }
                    }
                    else if (iResult == 0) {
                        printf("Connection closing...\n");
                        break;
                    }
                    else {
                        printf("recv failed with error: %d\n", WSAGetLastError());
                        closesocket(ClientSocket);
                        WSACleanup();
                        return 1;
                    }

                } while (iResult > 0);



                // shutdown the connection since we're done
                iResult = shutdown(ClientSocket, SD_SEND);
                if (iResult == SOCKET_ERROR) {
                    printf("shutdown failed with error: %d\n", WSAGetLastError());
                    closesocket(ClientSocket);
                    WSACleanup();
                    return 1;
                }
            }

        // cleanup
        closesocket(ClientSocket);
        WSACleanup();
        // No longer need server socket
        closesocket(ListenSocket);

    return 0;
}