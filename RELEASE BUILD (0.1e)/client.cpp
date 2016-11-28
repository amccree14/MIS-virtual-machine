/******************
* FILE: client.cpp
* Author: K. Sobh (prof), Arthur Kung
* Date: Nov 27, 2016
*
* Details:
*	- I've adjusted the main() function to send and receive files,
*		as well as check for parser errors by loading an MIS System
*		to parse the file before sending.
******************/


#include "includes.h"
#include "common.h"

#include "MIS.h"
#include <string>
#include <iostream>
#include <dlfcn.h>

#define MAX_BUF_LENGTH 1050

// A function to print an error message and terminate
void terminate_with_error (const char * error_msg,int sock)
{
	printf ("%s\n",error_msg); // printing error
	perror("Socket Error:"); // printing system error
	if (sock != -1) // Close socket and exit is socket opened
	{
		close (sock);
		exit(1);
	}
}

int main (int argc,char ** argv)
{
	if ( argc != 3) 
	{ // Check on the number of arguments and exit if incorrect
		printf ("Usage: ./client <server-address> <file.mis>\n");
		exit(1);
	}
	
	
		// store our potential filename into a string
	std::string s(argv[2]);
	
	
		// Dynamically load our MIS System	
	MIS_F* MIS_Run;
	
		// RTLD_LAZY = bind functions on call, not on open
	void * dll=dlopen ("./MIS.so",RTLD_LAZY);
	
		// if the DLL opened successfully, then...
	if (dll)
	{
// 			std::cout << "- SUCCESS: MIS System successfully "
// 						<< "dynamically loaded!\n\n"
// 						<< std::endl;
			//	load external functions and set them to pointers in the
			//	Command_DLL struct
			
			// attempt to load the MIS entry point
		if (!(MIS_Run = (MIS_F*)dlsym(dll,"MIS")))
		{
			std::cout << "\n\tCould not load MIS System: " 
						<< dlerror() << std::endl;
			return 1;
		}
	}
	else 
	{
		std::cout << "Failure to load dynamic library: "
					<< dlerror() << std::endl; 
		return 1;
	}
	
	
		// attempt to parse our file with our MIS System
	if (!(MIS_Run(s, false)))
	{
		std::cout << "MIS system either found errors during the parse"
					<< " or could not open the file.\n\n"
					<< "File not sent to server, please correct problems.\n";
		return 1;
	}
	
	
	
	int sock; // Socket handler
	struct sockaddr_in serverAddr; // Server address
	socklen_t sin_size = sizeof(struct sockaddr_in); // get size of server address
	// Try to create a socket and print an error message and exit if failed
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error Creating Socket");
		exit(1);
	}
	memset((char *) &serverAddr, 0,sizeof(serverAddr)); // initialize the server address data structure
	serverAddr.sin_family = AF_INET; // Set up the communication family
	serverAddr.sin_port = htons(9999); //set the port of the server
	struct hostent *server = gethostbyname(argv[1]); // convert the host name into a network host structure
	if ( server == NULL ) 
		terminate_with_error("error",sock); // if failed terminate with an error message
	// copy Server address data into server address structure
	memcpy((char *)&serverAddr.sin_addr.s_addr,(char *)server->h_addr, server->h_length);
	memset(&(serverAddr.sin_zero), 0, 8); // Zero out the rest of the address structure
	// try to connect to the server and exit with an error message if failed
	if (connect(sock,(sockaddr *)&serverAddr,sizeof(serverAddr)) == -1 ) 
		terminate_with_error("error",sock);
// 	send (sock,"test.txt",strlen("test.txt"),0); // Send a message to the server.







		// SEND .MIS FILE
	std::string filename(s);

	FILE * f = fopen(filename.c_str(),"r"); // Try to open the file
	if ( f != NULL)
	{ // If opened
		fseek (f,0,2); // Seek to the end of the file
		long fsize = ftell(f); // Get current location which represents the size
		char * buffer = (char *) calloc(fsize+1,sizeof(char)); // Allocate a buffer with the file size to read the content
		fseek (f,0,0); // Seek the beginning of the file
		fread(buffer,1,fsize,f); // Read the whole file into the buffer
		
		
		send (sock,buffer,fsize,0);
		
// 		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket
// 		std::this_thread::sleep_for(std::chrono::milliseconds(6000));
// 		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket
		
		free(buffer); // Free the buffer
		fclose(f); // Close the file
	}
	else 
	{
		perror("Error With File .mis\n"); // Print an error message
// 		tcpSocket->writeToSocket("Error\n",6);// Write error to the socket
	}


	std::cout << "\n\t\t- Done sending.\n\n";


		// RECEIVE AND WRITE FILES
	
	int bytesReceived = 0;
	std::ofstream o_mis, o_err;
	
	char buffer[MAX_BUF_LENGTH+1]; // A buffer for holding the inbound data
	memset (buffer,0,MAX_BUF_LENGTH+1); // Initialize the buffer
	
	
	int filetype;
	if ((filetype = s.rfind(".mis")) != std::string::npos)
	{
		s.erase(filetype, 4);
	}
	
	
		// initialize our received byte counter
	unsigned long long bytetotal = 0;
	
		// create our .err file and receive the data for it
		//	from our socket
	filename = s;
	filename += ".err";
	
	o_mis.open(filename, std::ofstream::out);
	if (o_mis.fail())
	{
		std::cout << "Error creating file .err.\n" << std::endl;
		return 1;
	}
		// since we're being sent a file over TCP, we know when the
		//	file is done being sent, because we'll receive a packet
		//	that is less than the maximum buffer size.
		
		// until we receive that smaller packet, keep looping.
	do 
	{
        memset (buffer,0,MAX_BUF_LENGTH+1); // clear buffer
	    bytesReceived = recv(sock, buffer, MAX_BUF_LENGTH, 0);
// 	    std::cout << "\tReceiving data: " << bytesReceived << " bytes"
// 	    			<< std::endl;
	    o_mis << buffer;
	    bytetotal += bytesReceived;
	} while ( bytesReceived == MAX_BUF_LENGTH );

	o_mis.flush();
	o_mis.close();

	std::cout << "Done writing file: " << filename 
				<< " (" << bytetotal << " bytes)" << std::endl;

				
		// reset our total bytes received counter for the next file
	bytetotal = 0;
	
	
		// create our .out file and receive the data for it
		//	from our socket
	filename = s;
	filename += ".out";
	
	o_err.open(filename, std::ofstream::out);
	if (o_err.fail())
	{
		std::cout << "Error creating file .out.\n" << std::endl;
		return 1;
	}
		// since we're being sent a file over TCP, we know when the
		//	file is done being sent, because we'll receive a packet
		//	that is less than the maximum buffer size.
		
		// until we receive that smaller packet, keep looping.
	do 
	{
        memset (buffer,0,MAX_BUF_LENGTH+1); // clear buffer
	    bytesReceived = recv(sock, buffer, MAX_BUF_LENGTH, 0);
// 	    std::cout << "\tReceiving data: " << bytesReceived << " bytes"
// 	    			<< std::endl;
	    o_err << buffer;
	   	bytetotal += bytesReceived;
	} while ( bytesReceived == MAX_BUF_LENGTH );
	
	o_err.flush();
	o_err.close();
	
	std::cout << "Done writing file: " << filename 
				<< " (" << bytetotal << " bytes)" << std::endl;
	
	
	std::cout << std::endl;
	
	
	
	
	close(sock);// Close the socket.
}

