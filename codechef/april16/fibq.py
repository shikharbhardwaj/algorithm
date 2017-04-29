from functools import reduce
_phi = (5.**0.5 + 1.)/2.

A = lambda n: _phi**n
B = lambda n: (-_phi)**(-n)
prod = lambda it: reduce(lambda x, y: x*y, it)
subset_sum = lambda s: (prod(A(n)+1 for n in s) - prod(B(n)+1 for n in s))/5**0.5
print(int((subset_sum([12, 13, 1000000000]))%(1e9+7)))

