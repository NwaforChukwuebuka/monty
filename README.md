Monty - Monty Bytecode Interpreter
Overview
Monty is a scripting language that is compiled into Monty Bytecodes, similar to Python. The language relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty Bytecode files.

Monty bytecode files typically have a .m extension and contain one instruction per line. The files follow a specific format with opcodes and their arguments. The interpreter reads these files and executes the corresponding instructions.

Project Structure
monty.h: Header file containing function prototypes and standard C library headers.
monty.c: Main file containing the main function.
command_parser.c: Functions for file reading, number checking, and forking.
monty_math_functions.c: Functions for mathematical operations (add, subtract, multiply, divide, mod).
monty_stack_easy.c: Functions for stack and queue operations (push, pall, swap).
monty_stack_medium.c: Additional stack functions for printing characters (pchar) and handling the nop opcode.
Instructions
Compilation
Compile the program using the following command:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
Usage
Run the compiled executable with a Monty bytecode file:

bash
Copy code
./monty path/to/your/file.m
Example
c
Copy code
// Example Monty Bytecode File (file.m)
push 1
push 2
push 3
pall
bash
Copy code
./monty file.m
Output:

Copy code
3
2
1
Task List
push, pall: Implement the push and pall opcodes.
pint: Implement the pint opcode.
pop: Implement the pop opcode.
swap: Implement the swap opcode.
add: Implement the add opcode.
nop: Implement the nop opcode.
sub: Implement the sub opcode.
div: Implement the div opcode.
mul: Implement the mul opcode.
mod: Implement the mod opcode.
comments: Implement commenting capability using #.
pchar: Implement the pchar opcode.
pstr: Implement the pstr opcode.
rotl: Implement the rotl opcode.
rotr: Implement the rotr opcode.
Requirements
Editors: vi, vim, emacs
Compilation on Ubuntu 14.04 LTS
Compilation with gcc 4.8.4 using flags -Wall -Werror -Wextra -pedantic
Files must end with a new line
Use Betty style for code (checked with betty-style.pl and betty-doc.pl)
Maximum of one global variable
No more than 5 functions per file
C standard library allowed
Prototypes of functions should be included in the header file monty.h
Header files should be include guarded
Author
Nwafor Chukwuebuka
