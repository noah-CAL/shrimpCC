# shrimpCC — the tiny C compiler
Based off the white paper [An Incremental Approach to Compiler Construction](http://scheme2006.cs.uchicago.edu/11-ghuloum.pdf).

Source Language: C

Implementation Language: also C

Target Architecture: x86_64-linux-gnu

## Supported Features

The following features are supported (based loosely off the above white paper):

+ Constant return values

More to come soon!

## Building the Compiler
The only requirements are `gcc` and `make`, and optionally `CUnit` and `python3` for running the unit/integration test suite. 

### Installing CUnit
```
>$ sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

#include <CUnit.h>
...
```
and link with `-lcunit` (which is already done in the Makefile)

### Running unit tests (TODO: update)

### Running Integration Tests

```
>$ make
USAGE: make [all, clean, help, ...]

>$ make all

>$ ./shrimpCC input_file.c
Successfully compiled input_file.c to program.s

>$ gcc program.s main.c && ./a.out  # link the assembly with a main function
Hello world!
```
## Unit/Integration Tests

The structure of the unit tests is defined as follows:
```
└─ tests
    ├── 0_return
    │   ├── test.in
    │   ├── test.ref
    │   └── test.c
    ├── 0_return_multiple
    │   ├── test.in
    │   ├── test.ref
    │   └── test.c
    ├── 1_return_boolean
    ...
    ├── README.md
    └── unittests.py
```
Each directory corresponds to one test case and has:

+ `test.in`: the input C code that gets passed into the compiler.
+ `test.c`: a driver / main function that tests the functions declared in `test.in`.
+ `test.ref`: the reference file containing the expected output after running `test.c`.

Rather than testing specific compiler implementations (such as testing for "`return 42` always translates to `movl $42, %eax; ret`"), 
these tests are implementation-specific and ensure that future additions to the compiler do not break the tests as long as the functionality isstill there.

KEY IDEA: tests are *implementation-agnostic* so that if it works, it works.

```
>$ make run-unit-tests
[Error]: shrimpCC not found in base directory. Ensure that the executable name matches unittests.py and that the program is compiled.

>$ make all
gcc -c src/compile.c -o src/compile.o -ggdb -Wall ...

>$ make run-unit-tests
Successfully compiled tests/0_return/test.in to tests/0_return/test.s
Successfully compiled tests/...
Ran 10 tests in ...
```
