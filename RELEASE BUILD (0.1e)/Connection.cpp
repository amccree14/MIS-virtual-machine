/******************
* FILE: Connection.cpp
* Author: K.Sobh (prof), Arthur Kung
* Date: Nov 27, 2016
*
* Details:
*	- I've adjusted the threadMainBody function heavily. It now
*		creates a .mis file and creates and runs our MIS System
*		before sending the output files back over the network.
******************/

#include <iostream>
#include "Connection.h"
#include <fstream>		// file i/o
#include <chrono>
#include <thread>
#include <string>
#include <sstream>

#include "MIS.h"
#include <dlfcn.h>

#define MAX_BUF_LENGTH 1050	// not 1023, because I want some space to test line-things

//Constructor: Call parent Thread Constructor
Connection::Connection(TCPSocket * p_tcpSocket): Thread()
{
	tcpSocket = p_tcpSocket; // Set the TCP socket
	next_connection = NULL; // Set the next pointer to NULL
} // A modifier that sets the pointer of the next connection

void Connection::setNextConnection(Connection * connection){next_connection = connection;}
	// A Selectot that returned a pointer to the next connection
Connection * Connection::getNextConnection (){return next_connection;}
	// Destructor: delete the TCP socket if set
Connection::~Connection(){if ( tcpSocket != NULL ) delete (tcpSocket);}







void * Connection::threadMainBody (void * arg) 
{ // Main thread body for serving the connection
	char buf[MAX_BUF_LENGTH+1]; // A buffer for holding the file name
	memset (buf,0,MAX_BUF_LENGTH+1); // Initialize the buffer
	int read_bytes;// = tcpSocket->readFromSocket(file_name,1023); // read from socket the file name to be fetched
	
	
	
		// create a file named after the pointer to the current socket object
		//	and save it as a .mis file. Store the incoming file into it.
		
		// this is important, because each socket has a unique pointer to it,
		//	and therefore we will never have multiple threads using the same
		//	filenames.
	std::stringstream ss;	
	ss << tcpSocket;
	
	std::string s = ss.str();
	
	std::ofstream o_mis;
		// open/create the [socket_pointer].mis file
	o_mis.open(s+".mis", std::ofstream::out);
	
		// if the file isn't created for some reason, then...
	if (o_mis.fail())
	{
		std::cout << "failure to create files\n";
			// send an Error report for each file that the client is
			//	expecting.
		tcpSocket->writeToSocket("Error\n",6);// Write error to the socket
		tcpSocket->writeToSocket("Error\n",6);// Write error to the socket
	}
	
		// create a counter for total byte size of our received file
	unsigned long long totalbytes = 0;
	
		// receive our file from the network on our socket
	do
	{
		read_bytes = tcpSocket->readFromSocket(buf,MAX_BUF_LENGTH);
		//std::cout << "bytes received: " << read_bytes << std::endl;
		totalbytes += read_bytes;
		if (read_bytes < MAX_BUF_LENGTH)
			buf[read_bytes] = '\0';
		o_mis << buf;
	}while (read_bytes == MAX_BUF_LENGTH);
	
		// close our newly made .mis file
	o_mis.close();

	std::cout << "Filesize received: " << totalbytes << " bytes.\n" 
				<< std::endl;
	std::cout << "\n\t\t-Loading MIS System.\n";
	
	
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
			return 0;
		}
	}
	else 
	{
		std::cout << "Failure to load dynamic library: "
					<< dlerror() << std::endl; 
		return 0;
	}
	
	
	std::cout << "\n\t\t-MIS System Loaded.\n\n--------------------\n\n";
	
	
		// ignore the return from MIS_Run, because we don't care
		//	if there are errors. We're sending the output files
		//	back no matter what.
	std::string filename(s);
	filename += ".mis";
		
	MIS_Run(filename, true);
		
	std::cout << s << ".mis" << std::endl;
	
	filename = s;
	filename += ".err";
	
	std::cout << "Sending: " << filename << std::endl;
	
	FILE * f = fopen(filename.c_str(),"r"); // Try to open the file
	if ( f != NULL)
	{ // If opened
		fseek (f,0,2); // Seek to the end of the file
		long fsize = ftell(f); // Get current location which represents the size
		char * buffer = (char *) calloc(fsize+1,sizeof(char)); // Allocate a buffer with the file size to read the content
		fseek (f,0,0); // Seek the beginning of the file
		fread(buffer,1,fsize,f); // Read the whole file into the buffer
		
		//std::cout << "\tbytes: " << fsize << std::endl;
		
			// if fsize is 0, increment it so a packet will be sent,
			//	otherwise leave it alone because TCP handles the hard
			//	parts of syncing etc.
		if (fsize == 0)
			++fsize;
		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket

		
// 		std::this_thread::sleep_for(std::chrono::milliseconds(6000));
// 		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket
// 		tcpSocket->writeToSocket(buffer,0); // Write the buffer to the socket
		
		free(buffer); // Free the buffer
		fclose(f); // Close the file
	}
	else 
	{
		perror("Error With File .err\n"); // Print an error message
		tcpSocket->writeToSocket("Error\n",6);// Write error to the socket
	}
	

	
	
	filename = s;
	filename += ".out";
	
	std::cout << "Sending: " << filename << std::endl;
	
	f = fopen(filename.c_str(),"r"); // Try to open the file
	if ( f != NULL)
	{ // If opened
		fseek (f,0,2); // Seek to the end of the file
		long fsize = ftell(f); // Get current location which represents the size
		char * buffer = (char *) calloc(fsize+1,sizeof(char)); // Allocate a buffer with the file size to read the content
		fseek (f,0,0); // Seek the beginning of the file
		fread(buffer,1,fsize,f); // Read the whole file into the buffer
		
		//std::cout << "\tbytes: " << fsize << std::endl;
		
			// if fsize is 0, increment it so a packet will be sent,
			//	otherwise leave it alone because TCP handles the hard
			//	parts of syncing etc.
		if (fsize == 0)
			++fsize;
		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket

		
// 		std::this_thread::sleep_for(std::chrono::milliseconds(6000));
// 		tcpSocket->writeToSocket(buffer,fsize); // Write the buffer to the socket
// 		tcpSocket->writeToSocket(buffer,0); // Write the buffer to the socket
		
		free(buffer); // Free the buffer
		fclose(f); // Close the file
	}
	else 
	{
		perror("Error With File .out\n"); // Print an error message
		tcpSocket->writeToSocket("Error\n",6);// Write error to the socket
	}
	
	
	
	
	
		// delete all created files
	filename = s;
	filename += ".mis";
	std::remove(filename.c_str());
	filename = s;
	filename += ".err";
	std::remove(filename.c_str());
	filename = s;
	filename += ".out";
	std::remove(filename.c_str());
	
	tcpSocket->shutDown(); // Shutdown the TCP Socket
	return NULL;
}


