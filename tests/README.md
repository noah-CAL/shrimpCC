# shrimpCC Unit Tests

The structure of the unit tests is defined as follows:

tests
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

Each directory corresponds to one test case and has:

+ `test.in`: the input C code that gets passed into the compiler.
+ `test.c`: a driver / main function that tests the functions declared in `test.in`.
+ `test.ref`: the reference file containing the expected output after running `test.c`.

Rather than testing specific compiler implementations (such as testing for "`return 42` always translates to `movl $42, %eax; ret`"), 
these tests are implementation-specific and ensure that future additions to the compiler do not break the tests as long as the functionality isstill there.

KEY IDEA: tests are *implementation-agnostic* so that if it works, it works.

