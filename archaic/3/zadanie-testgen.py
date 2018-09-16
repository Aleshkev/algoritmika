from random import *

def calc(s):
    n = len(s)
    calc = [0] * n
    for i in range(1, n):
        calc[i] = 0
        for j in range(1, i + 1):
            if s[0:j] == s[i - j + 1:i + 1]:
                calc[i] = max(calc[i], j)
    return calc

def gen(n = 10):
    s = "".join(choice(['a'] * 5 + ['b'] * 1) for _ in range(n))
    return s, " ".join(map(str, calc(s)))

def qgen(m = 100, n = 10):
    return "{}\n{}".format(m, "\n".join("{} {}".format(n, gen(n)[1])
                                        for _ in range(m)))

print(qgen())
