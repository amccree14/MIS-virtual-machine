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
  - LABEL
  - JMP
  - JMPZNZ
  - JMPGTLTE
  - JMPGTELT
  - SLEEP
  - VAR
  
Command class parameter creator
  - Takes a parameter and parses it into a PARAM object, returns an OP_PARAM_BASE pointer
  - It is expected that the parsers all check the returned OP_PARAM_BASE pointers for acceptable parameter types for their opcodes
  
Param class setter/getters/constructors
  - PARAM
  - VARIABLE
  - V_PARAM

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
  - LABEL
  - JMP
  - JMPZNZ
  - JMPGTLTE
  - JMPGTELT
  - SLEEP
  - VAR
  
  
# To-Do (Marlo)
UML Diagrams
   - Class
   - Sequence
   - Use


# Additional Notes

(Arthur, 11/7/16)
  Fortunately, it looks like everything we're working on can be split into individual .cpp files, so there's no direct overlap. I'll hammer out the rest of my stuff tonight.
