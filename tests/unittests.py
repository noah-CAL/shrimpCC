import filecmp
import os
import subprocess
import sys
import unittest

COMPILER = "main.out"

test_dirs = (
    "0_return"
)

class TestBasic(unittest.TestCase):
    # TODO: this is a very rough general idea for unit tests for my compiler.
    # This will eventually be modularized, but works with the first simple test case 
    # for the time being...
    def test_0_return(self):
        # Step 1: Compile the input code
        command = [f"./{COMPILER}", "tests/0_return/0_basic.in", "tests/0_return/0_basic.s"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        # Step 2: link the input code
        command = [f"gcc", "tests/0_return/0_test.c", "tests/0_return/0_basic.s", "-o", "tests/0_return/0_basic.exe"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        # Step 3: assert equality of the output
        command = ["tests/0_return/0_basic.exe"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        self.assertTrue(filecmp.cmp("tests/0_return/0_basic.ref", "tests/0_return/0_basic.out"))

if __name__ == '__main__':
    if not os.path.isfile(COMPILER):
        print(f"[Unit Tests Error]: {COMPILER} not found in base directory. "
               "Ensure that the executable name matches unittests.py and that the program is compiled.")
        sys.exit(-1)
    unittest.main()
