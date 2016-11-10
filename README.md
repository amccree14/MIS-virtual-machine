# MIS-virtual-machine
CS109 project

# Current Version: 0.1a (Nov 10 2016)
**Changes:**
  - moved overloaded to_string function template out of the std namespace and into the dbg namespace to avoid undefined behaviour.


## To-Do (Arthur)
Command class internal parsers ***(complete 11/8)***
  - ~~ADD~~
  - ~~SUB~~
  - ~~MUL~~
  - ~~DIV~~
  - ~~ASSIGN~~
  - ~~OUT~~
  - ~~SET_STR_CHAR~~
  - ~~GET_STR_CHAR~~
  - ~~LABEL (no execute, should throw exception if execute is called)~~
  - ~~JMP~~
  - ~~JMPZNZ~~
  - ~~JMPGTLTE~~
  - ~~JMPGTELT~~
  - ~~SLEEP~~
  - ~~VAR (no execute, should throw exception if execute is called)~~
  
  *VAR and LABEL are special case commands that are not added to the command vector and are execute on the spot*
  
Command class parameter creator ***(complete 11/7)***
  - ~~Takes a parameter and parses it into a PARAM object, returns an OP_PARAM_BASE pointer~~
  - ~~It is expected that the parsers all check the returned OP_PARAM_BASE pointers for acceptable parameter types for their opcodes~~
  
Command class generic addParam(OP_Param_Base pointer) function ***(complete 11/8)***
  - ~~converts an OP_Param_Base pointer to a shared pointer and pushes it onto the Command class's internal vector~~
  
OP_Param_Base class setter/getters/constructors ***(complete 11/8)***
  - ~~Params~~
  - ~~Variable~~
  - ~~V_Param~~
  
Create user-facing interface and MIS_System wrapper ***(complete 11/8)***
  - ~~MIS.cpp~~

Create additional systems to flesh out system ***(complete 11/9)***
  - ~~file-output system~~
  - ~~post-parse Label linking system~~

## To-Do (Andrew)
Command class executes ***(complete 11/9)***
  - ~~ADD~~
  - ~~SUB~~
  - ~~MUL~~
  - ~~DIV~~
  - ~~ASSIGN~~
  - ~~OUT~~
  - ~~SET_STR_CHAR~~
  - ~~GET_STR_CHAR~~
  - ~~JMP~~
  - ~~JMPZNZ~~
  - ~~JMPGTLTE~~
  - ~~JMPGTELT~~
  - ~~SLEEP~~
  
  
## To-Do (Marlo) 
UML Diagrams ***(complete 11/9)***
   - ~~Class~~
   - ~~Sequence~~
   - ~~Use~~
   
   
## To-Do (Other) 
~~Debug~~, ~~Makefile~~ ***(complete 11/9)***

## Known Issues
  - Submitted revision *may* not compile on some systems. Release 0.1 has an overloaded function in the std namespace, which causes undefined behaviour. This has been fixed in release 0.1a.  
  - Commenting is sparse in some files, due to time constraints.


## Additional Notes

(Arthur, 11/8/16) Yay. Time to create a user-facing interface and start the long debug haul. (update: created user-interface, waiting on completion of rest of code to do full debugging. Partial debug underway)

(Arthur, 11/7/16) - Fortunately, it looks like everything we're working on can be split into individual .cpp files, so there's no direct overlap. I'll hammer out the rest of my stuff tonight.
