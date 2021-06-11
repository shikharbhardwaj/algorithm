import math
from enum import Enum

class PREF_MATCH(Enum):
    LESS = 0
    MORE = 1
    SAME = 2

def get_match(a, b):
    str_a, str_b = str(a), str(b)

    for i in range(min(len(str_a), len(str_b))):
        if str_a[i] != str_b[i]:
            return PREF_MATCH.LESS if str_a[i] < str_b[i] else PREF_MATCH.MORE

    return PREF_MATCH.SAME


def is_possible_to_increment(prev, cur):
    return get_match(prev + 1, cur) == PREF_MATCH.SAME


def cost(x, y):
    return abs(len(str(x)) - len(str(y)))


def pad_zeros(a, n):
    return int(a * math.pow(10, n))


def try_increment_or_pad(prev, cur):
    if is_possible_to_increment(prev, cur):
        return prev + 1
    else:
        return pad_zeros(cur, len(str(prev)) - len(str(cur)) + 1)


def solve(x):
    ans = 0
    prev = x[0]

    for i in range(1, len(x)):
        if x[i] > prev:
            prev = x[i]
            continue
        
        cur = x[i]
        match = get_match(x[i], prev)

        if match == PREF_MATCH.SAME:
            x[i] = try_increment_or_pad(prev, x[i])
        elif match == PREF_MATCH.MORE:
            x[i] = pad_zeros(x[i], len(str(prev)) - len(str(x[i])))
        elif match == PREF_MATCH.LESS:
            x[i] = pad_zeros(x[i], len(str(prev)) - len(str(x[i])) + 1)
        
        ans += cost(cur, x[i])
        prev = x[i]
    
    return ans




if __name__ == "__main__":
    # solve([100, 7, 10])
    C = int(input())

    for case_num in range(1, C + 1):
        N = int(input())

        x = [int(x) for x in input().split()]

        ans = solve(x)

        print(f"Case #{case_num}: {ans}")