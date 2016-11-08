# MIS-virtual-machine
CS109 project


# To-Do (Arthur)
Command class internal parsers
  - ADD
  - SUB
  - MUL
  - DIV
  - ASSIGN
  - OUT
  - SET_STR_CHAR
  - GET_STR_CHAR
  - LABEL (+execute)
  - JMP
  - JMPZNZ
  - JMPGTLTE
  - JMPGTELT
  - SLEEP
  - VAR (+execute)
  
  *VAR and LABEL are special case commands that are not added to the command vector and are execute on the spot*
  
Command class parameter creator
  - Takes a parameter and parses it into a PARAM object, returns an OP_PARAM_BASE pointer
  - It is expected that the parsers all check the returned OP_PARAM_BASE pointers for acceptable parameter types for their opcodes
  
Command class generic addParam(OP_Param_Base pointer) function
  - converts an OP_Param_Base pointer to a shared pointer and pushes it onto the Command class's internal vector
  
OP_Param_Base class setter/getters/constructors
  - Params
  - Variable
  - V_Param

# To-Do (Andrew)
Command class executes
  - ADD
  - SUB
  - MUL
  - DIV
  - ASSIGN
  - OUT
  - SET_STR_CHAR
  - GET_STR_CHAR
  - JMP
  - JMPZNZ
  - JMPGTLTE
  - JMPGTELT
  - SLEEP
  
  
# To-Do (Marlo)
UML Diagrams
   - Class
   - Sequence
   - Use
   
   
# To-Do (Other)
Debug, Makefile

# Known Issues
  - Commenting is sparse in some files, due to time constraints.
  - Labels currently cannot have names that start with numerals. Will be fixed later, if necessary.


# Additional Notes

(Arthur, 11/7/16) - Fortunately, it looks like everything we're working on can be split into individual .cpp files, so there's no direct overlap. I'll hammer out the rest of my stuff tonight.
