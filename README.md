# Assembly-Interpreter
This C++ assembly interpreter processes Assembly-like instructions and executes them. It supports basic arithmetic operations, conditional jumps, and other assembly commands. The interpreter reads input from a file and outputs either to the console or another file based on the specified command line arguments.

Key Features:

-Supports 16-bit, 32-bit, and 64-bit registers (ax, bx, cx, dx, eax, ebx, ecx, edx, rax, rbx, rcx, rdx).
-Handles integer and .asciz (string) data types.
-Parses and executes assembly commands, including basic arithmetic operations (mov, add, sub, mul, div).
-Supports conditional jumps based on comparison results (je, jg, jge, jl, jle, jne). -- NOT DONE
-Other Commands:  push, pop, lea, jmp, loop -- NOT DONE
-Error Handling: Provides error messages for missing commas, unsupported commands, and incorrect command syntax.

Usage: ./assembler input_file output_file or ./assembler input_file for console output
