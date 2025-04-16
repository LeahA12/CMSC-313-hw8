## AUTHORING: 
* Leah Arfa
* UMBC class CMSC 313
* April 15th 2025

## PURPOSE OF SOFTWARE: 
* This software contains a c++ and c implementation of matrix addition, scalar multiplication, matrix multiplication, and transposition.
  
## FILES: 
* matrixC.h = The C header file that contains the Matrix structure's declaration and the matrix operations' function prototypes.
* matrixC.c = The C source file that contains the definitions of all functions declared in 'matrixC.h'.
* mainC.c = The C driver file that contains the 'main' function, using 'matrixC.h' to solve a matrix equation.
* matrix.h = The C++ header file that contains the Matrix Class and its private and public members.
* matrix.cpp = The C++ source file that contains the definitions of all functions declared in 'matrix.h'.
* main.cpp = The C++ driver file that contains the 'main' function, using 'matrix.h' to solve the same matrix equation as the C code solves.
   
BUILD INSTRUCTIONS: 
* To write a matrix library in both C++ and C that will successfully solve the following equation: ![image](https://github.com/user-attachments/assets/41d3650a-9ae1-4b89-b891-cea14fb16db1)

TESTING METHODOLOGY: 
* We solve the same equation D = A + (3*B) * D^T for the C code and the C++ code.
* The output is the same for the C Code and the C++ code.

ADDITIONAL INFORMATION:
* I used vectors to create a matrix for the C++ version.
* I used pointer to create a matrix for the C version.
