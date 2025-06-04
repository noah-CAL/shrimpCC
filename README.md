# shrimpCC — the tiny C compiler
Based off the white paper [An Incremental Approach to Compiler Construction](http://scheme2006.cs.uchicago.edu/11-ghuloum.pdf).

Source Language: C

Implementation Language: also C

Target Architecture: x86_64-linux-gnu

## Building the Compiler
The only requirements are `gcc` and `make`, and optionally `python3` for running the unit/integration test suite. 

```
>$ make
USAGE: make [all, clean, help, ...]

>$ make all

>$ ./shrimpCC input_file.c
Successfully compiled input_file.c to program.s

>$ gcc program.s main.c && ./a.out  # link the assembly with a main function
Hello world!
```
