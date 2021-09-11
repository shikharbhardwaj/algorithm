
'''

The Dutch National Flag problem


Given an array [x0, x1, x2..., xi, ...] with xi ∈ {0, 1, 2}

Re-order the array s.t. [0, 0, 0, ..., 1, 1, 1 ..., 2, 2, 2]

Do this without using auxiliary space.


Solution:

1. Counting sort
2. Two pointers



'''

import random
from typing import List
import unittest

def partition(pivot, xs: List[int]):
    smaller, equal, larger = 0, 0, len(xs)

    while equal < larger:
        if xs[equal] < pivot:
            xs[equal], xs[smaller] = xs[smaller], xs[equal]
            smaller, equal = smaller + 1, equal + 1
        elif xs[equal] == pivot:
            equal += 1
        else:
            larger -= 1
            xs[equal], xs[larger] = xs[larger], xs[equal]
    
    return xs


class DutchNationalFlagTests(unittest.TestCase):

    def test_trivial_case(self):
        original_xs = [0, 0, 0, 1, 1, 2, 2]

        sorted_xs = partition(1, list(original_xs))

        return self.assertEqual(original_xs, sorted_xs)

    def test_case_1(self):
        original_xs = [0, 0, 0, 1, 1, 2, 2]

        jumbled_xs = list(original_xs)

        random.shuffle(jumbled_xs)

        sorted_xs = partition(1, list(jumbled_xs))

        return self.assertEqual(original_xs, sorted_xs)

if __name__ == '__main__':
    unittest.main()
