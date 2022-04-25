# Gauss Elimination

Program made during laboratory classes of "Języki i Metody Programowania 1" during first term of Applied Computer Science. Our goal was desing a program which read matrixes from files and find the solution by doing gauss elimination. Program has two modes but to use second of them you have to use flag `-USE_MAX` which means that gauss elimination will use find max method.

# Programs compilation

Compilation is made with command:\
```make```\
To delete working files made during compilation:\
```make clean```\

# Running program

To run program you have to give every argument in correct order.\
`./matrix [file] [result matrix] [optional flag]`

# Tests

To compile test program use:\
`make test`\
To run tests you have to compile them like above and then use command:\
`./test`

