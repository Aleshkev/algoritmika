from random import *
from itertools import *
from collections import *
from functools import *


d = {(): False}


def solve(state, indent=0):
    state = tuple(sorted(state))
    if state in d.keys():
        return d[state]

    if len(state) == 1:
        return True

    def x():
        for i in range(len(state)):
            for take in range(1, state[i]):
                for n in range(0, 4):
                    for p in combinations_with_replacement(range(1, take + 1), n):
                        new = tuple(sorted(
                            state[:i] + ((state[i] - take,) if state[i] > take else 0) + state[i + 1:] + p))
                        if not solve(new, indent + 1):
                            return True
            new = tuple(sorted(state[:i] + state[i + 1:]))
            if not solve(new, indent + 1):
                return True
        return False

    d[state] = x()
    # print("  " * indent + str(state), d[state])
    return d[state]


def quick_solve(state):
    s = sorted(state)

    c = defaultdict(lambda: 0)
    for i in s:
        c[i] += 1

    for v in c.values():
        if v % 2 == 1:
            return True
    return False


ans = []
for n in range(1, 6):
    for p in combinations_with_replacement(range(1, 5), n):
        d = {}
        print(p, end=": ", flush=True)
        a = solve(p)
        b = quick_solve(p)
        print(solve(p), quick_solve(p), flush=False)
        if a != b:
            print("Wrong answer?")
