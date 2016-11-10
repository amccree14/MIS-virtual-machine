# Name: Arthur Kung
# cruzid: ajkung
# Class: CMPS109
# Assignment: Project

# Note: Based directly on old Makefiles, with minimal adjustment
# ===================================================================

CC     = g++
CFLAGS = -std=c++11

misvm: MIS.o MIS_System.o Command_Parsers.o Command_Param_Functions.o Command_Execute.o Variable.o helpers.o z_dbg.o
	${CC}  -o  misvm MIS.o MIS_System.o Command_Parsers.o Command_Param_Functions.o Command_Execute.o Variable.o helpers.o z_dbg.o
	
MIS.o:	MIS.cpp MIS_System.h MIS_Exception.h
	${CC}	-c ${CFLAGS} MIS.cpp

MIS_System.o:	MIS_System.cpp Command.h MIS_System.h MIS_Exception.h labelLink.h helpers.h z_dbg.h
	${CC}	-c ${CFLAGS} MIS_System.cpp

Command_Parsers.o:	Command_Parsers.cpp MAXMIN_ENUM.h OP_Param_Base.h Params.h Variable.h V_Param.h Command.h MIS_Exception.h MIS_System_Data.h helpers.h z_dbg.h
	${CC}	-c ${CFLAGS} Command_Parsers.cpp

Command_Param_Functions.o:	Command_Param_Functions.cpp OP_Param_Base.h Params.h Variable.h V_Param.h Command.h MIS_Exception.h MIS_System_Data.h helpers.h z_dbg.h
	${CC}	-c ${CFLAGS} Command_Param_Functions.cpp

Command_Execute.o:	Command_Execute.cpp Command.h MIS_System_Data.h OP_Param_Base.h MIS_Exception.h z_dbg.h
	${CC}	-c ${CFLAGS} Command_Execute.cpp

Variable.o:		Variable.cpp OP_Param_Base.h Variable.h MIS_System_Data.h
	${CC}	-c ${CFLAGS} Variable.cpp

helpers.o: 		helpers.cpp helpers.h MIS_Exception.h
	${CC}	-c ${CFLAGS} helpers.cpp

z_dbg.o:		z_dbg.cpp z_dbg.h
	${CC}	-c ${CFLAGS} z_dbg.cpp
	
	

	