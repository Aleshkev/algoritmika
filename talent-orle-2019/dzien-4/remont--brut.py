from itertools import *
from collections import *
from random import *
from pathlib import Path
from os import system


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def gen(n=10):
    t = [[]]
    for i in range(1, n):
        t[choice(range(len(t)))].append(i)
        t.append([])


def gen_ready(n=10):
    t = []
    for i in range(1, n):
        t.append(randrange(i) + 1)
    return f"{n}\n" + ' '.join(map(str, t)) + '\n'


def parse(s: str):
    z = s.splitlines()
    n = int(z[0])
    l = map(int, z[1].split())
    t = [[] for _ in range(n)]
    for i, e in enumerate(l):
        t[e - 1].append(i + 1)
    return n, t


p = 10**9 + 7


def solve(n, t):
    g = [[] for _ in range(n)]
    for i in range(n):
        for j in t[i]:
            g[i].append(j)
            g[j].append(i)

    ans = []

    for i in range(n):
        visited = [False] * n
        visited[i] = True

        dp = [1] * n

        def dfs(j):
            for k in g[j]:
                if visited[k]:
                    continue
                visited[k] = True
                dfs(k)
                dp[j] *= dp[k] + 1
        dfs(i)
        ans.append(dp[i] % p)
    return ans


x = 0
while True:
    ain = Path('a.in')
    aout = Path('a.out')

    g = gen_ready(100)
    ain.write_text(g)

    system('.\\a.exe < a.in > a.out')

    o = aout.read_text()
    # print(o.splitlines())
    o = list(map(int, o.splitlines()[0].split()))

    s = solve(*parse(g))

    if o != s:
        print("WOOOO")
        print(g)
        print("got", o)
        print("expected", s)
        break
    else:
        print(x)
        x += 1
