from itertools import *

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def bf(t):
    max_c = 0
    for u in powerset(t):
        ok = True
        for i in range(1, len(u) - 1):
            if (u[i - 1] <= u[i] <= u[i + 1] or
                u[i - 1] >= u[i] >= u[i + 1]):
                ok = False
                break
        if not ok:
            continue
        max_c = max(max_c, sum(u))
    return max_c
        
        
