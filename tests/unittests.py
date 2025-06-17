# shrimpCC: the tiny C compiler written in C!
#
# Copyright (C) 2025 Noah Sedlik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

import filecmp
import os
import subprocess
import sys
import unittest

COMPILER = "shrimpCC"

TEST_DIRS = (
    "0_return"
)


class TestBasic(unittest.TestCase):
    # TODO: this is a very rough general idea for unit tests for my compiler.
    # This will eventually be modularized, but works with the first test case
    # for the time being...
    def test_0_return(self):
        # Step 1: Compile the input code
        command = [f"./{COMPILER}", "tests/0_return/test.in",
                   "tests/0_return/test.s"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        # Step 2: link the input code
        command = ["gcc", "tests/0_return/test.c",
                   "tests/0_return/test.s", "-o", "tests/0_return/test.exe"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        # Step 3: assert equality of the output
        command = ["tests/0_return/test.exe"]
        output = subprocess.run(command, stdout=sys.stdout, stderr=sys.stderr)
        self.assertTrue(filecmp.cmp(
            "tests/0_return/test.ref", "tests/0_return/test.out"))


if __name__ == '__main__':
    if not os.path.isfile(COMPILER):
        print(f"[Unit Tests Error]: {COMPILER} not found in base directory. "
              "Ensure that the executable name matches unittests.py and that"
              "the program is compiled.")
        sys.exit(-1)
    unittest.main()
