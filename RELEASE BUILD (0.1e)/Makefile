# Name: Arthur Kung
# cruzid: ajkung
# Class: CMPS109
# Assignment: Project - Phase 2

# Note: Based directly on old Makefiles, with a couple adjustments
# ===================================================================

CC     = g++
CFLAGS = -std=c++11 -pthread -fmax-errors=5

default: MIS.so MIS.o MIS_System.o command.so Variable.o helpers.o z_dbg.o Threads.o Command_Parsers.o Command_Param_Functions.o Command_Execute.o Command_DLL_Entry.o client server client.o server.o Connection.o GarbageCollector.o TCPServerSocket.o TCPSocket.o Thread.o



client: client.o
	${CC}	${CFLAGS} client.cpp -o client -ldl
	
server: server.o Connection.o GarbageCollector.o TCPServerSocket.o TCPSocket.o Thread.o
	${CC}	${CFLAGS} Connection.o GarbageCollector.o server.o TCPServerSocket.o TCPSocket.o Thread.o -fmax-errors=5 -o server -ldl

client.o: 	client.cpp includes.h common.h MIS.h
	${CC}	-c ${CFLAGS} client.cpp
	
server.o: 	server.cpp GarbageCollector.h TCPServerSocket.h
	${CC}	-c ${CFLAGS} server.cpp

Connection.o:	Connection.cpp Connection.h MIS.h
	${CC}	-c ${CFLAGS} Connection.cpp -ldl

GarbageCollector.o:	GarbageCollector.cpp GarbageCollector.h
	${CC}	-c ${CFLAGS} GarbageCollector.cpp

TCPServerSocket.o: TCPServerSocket.cpp TCPServerSocket.h
	${CC}	-c ${CFLAGS} TCPServerSocket.cpp

TCPSocket.o: TCPSocket.cpp TCPSocket.h
	${CC}	-c ${CFLAGS} TCPSocket.cpp

Thread.o:	Thread.cpp Thread.h
	${CC}	-c ${CFLAGS} Thread.cpp
	
	
	
	
	
	
	
MIS.so: MIS.o MIS_System.o Variable.o helpers.o z_dbg.o Threads.o command.so
	${CC}	${CFLAGS} -shared -fPIC MIS.o MIS_System.o Variable.o helpers.o z_dbg.o Threads.o -ldl -o MIS.so
	
command.so:	Command_DLL_Entry.o Command_Parsers.o Command_Param_Functions.o Command_Execute.o helpers.o Variable.o Threads.o MIS_System.o z_dbg.o
	${CC}	${CFLAGS} -shared -fPIC Command_DLL_Entry.o Command_Parsers.o Command_Param_Functions.o Command_Execute.o MIS_System.o Threads.o Variable.o helpers.o z_dbg.o -o command.so
	
MIS.o:	MIS.cpp MIS_System.h MIS_Exception.h
	${CC}	-c ${CFLAGS} -shared -fPIC MIS.cpp -ldl

MIS_System.o:	MIS_System.cpp Command.h MIS_System.h MIS_Exception.h labelLink.h helpers.h z_dbg.h Threads.h
	${CC}	-c ${CFLAGS} -shared -fPIC MIS_System.cpp -ldl

Command_Parsers.o:	Command_Parsers.cpp MAXMIN_ENUM.h OP_Param_Base.h Params.h Variable.h V_Param.h Command.h MIS_Exception.h MIS_System_Data.h helpers.h z_dbg.h Threads.h
	${CC}	-c ${CFLAGS} -shared -fPIC Command_Parsers.cpp

Command_Param_Functions.o:	Command_Param_Functions.cpp OP_Param_Base.h Params.h Variable.h V_Param.h Command.h MIS_Exception.h MIS_System_Data.h helpers.h z_dbg.h
	${CC}	-c ${CFLAGS} -shared -fPIC Command_Param_Functions.cpp

Command_Execute.o:	Command_Execute.cpp Command.h MIS_System_Data.h OP_Param_Base.h MIS_Exception.h z_dbg.h Threads.h
	${CC}	-c ${CFLAGS} -shared -fPIC Command_Execute.cpp
	
Command_DLL_Entry.o:	Command_DLL_Entry.cpp Command_DLL_Struct.h MIS_System_Data.h Command.h
	${CC}	-c ${CFLAGS} -shared -fPIC Command_DLL_Entry.cpp
	
Variable.o:		Variable.cpp OP_Param_Base.h Variable.h MIS_System_Data.h
	${CC}	-c ${CFLAGS} -shared -fPIC Variable.cpp

helpers.o: 		helpers.cpp helpers.h MIS_Exception.h
	${CC}	-c ${CFLAGS} -shared -fPIC helpers.cpp

z_dbg.o:		z_dbg.cpp z_dbg.h
	${CC}	-c ${CFLAGS} -shared -fPIC z_dbg.cpp
	
Threads.o:		Threads.cpp Threads.h
	${CC}	-c ${CFLAGS} -shared -fPIC Threads.cpp
	
	

	
	
	
clean:
	${RM}	client server *.so *.o
	
	

	