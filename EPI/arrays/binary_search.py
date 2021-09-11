'''
### Revisiting the binary search algorithm


Assume there exists an array consisting of 0s and 1s, which looks like this

```
[0, 0, 0, 1, 1, 1]
```

We can ask some interesting questions like:

1. What is the index of the last 0? A: 2
2. What is the index of the first 1? A: 3


A linear (looking at each index one-by-one) search works here, but if the array
is guaranteed to be sorted (all 0s followed by all 1s), a much more efficient 
approach is possible.

This approach is called a binary search. It is a specific application of the bisection method.
'''


def first_true(L, R, pred):
    if L >= R:
        raise ValueError("Invalid range supplied.")
    
    while L < R:
        m = (L + R) // 2

        if pred(m):
            R = m
        else:
            L = m + 1
    
    # L should point to the first 1, or out of the range if all are 0s
    return L


def last_false(L, R, pred):
    if L >= R:
        raise ValueError("Invalid range supplied.")
    
    while L < R:
        m = (L + R) // 2

        if pred(m):
            R = m
        else:
            L = m + 1
    
    # L should point to the last 0, or out of the range if all are 1s
    return L - 1


import unittest

class TestBinarySearchMethods(unittest.TestCase):
    def test_first_true_answer_exists(self):
        xs = [0, 0, 0, 1, 1]

        first_true_idx = first_true(0, len(xs), lambda x: xs[x])

        self.assertEqual(first_true_idx, 3)

    def test_first_true_answer_does_not_exist(self):
        xs = [0, 0, 0, 0, 0]

        first_true_idx = first_true(0, len(xs), lambda x: xs[x])

        self.assertEqual(first_true_idx, 5)

    def test_last_false_answer_exists(self):
        xs = [0, 0, 0, 1, 1]

        last_false_idx = last_false(0, len(xs), lambda x: xs[x])

        self.assertEqual(last_false_idx, 2)

    def test_last_false_answer_does_not_exist(self):
        xs = [1, 1, 1, 1, 1]

        last_false_idx = last_false(0, len(xs), lambda x: xs[x])

        self.assertEqual(last_false_idx, -1)
    

if __name__ == '__main__':
    unittest.main()

