from math import *
from itertools import *

def is_square(n):
    if n in (0, 1): return True
    x = n // 2
    seen = {x}
    while x * x != n:
        x = (x + (n // x)) // 2
        if x in seen: return False
        seen.add(x)
    return True

def f(n = 200):
    t = [1]
    for i in range(2, n + 1):
        t.append(t[-1] * i)
    u = [is_square(i) for i in accumulate(t)]
    return u
    
