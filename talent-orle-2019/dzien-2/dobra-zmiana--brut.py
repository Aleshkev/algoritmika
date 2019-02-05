from itertools import *
from random import *
from os import *
from pathlib import *


def solve(n, m, graph):
    done = set()
    correct = set()
    for p in permutations([i // 3 + 1 for i in range(n)]):
        if p in done:
            continue
        done.add(p)

        ok = True
        for i in range(n):
            for j in graph[i]:
                if p[i] == p[j]:
                    ok = False
                    break
            if not ok:
                break
        if ok:
            correct.add(p)
    return correct


def gen():
    n, m = 9, 20

    l = [i for i in range(n) if random() < 0.5]
    r = [i for i in range(n) if i not in l]

    if not l:
        l.append(r[-1])
        r.pop()
    if not r:
        r.append(l[-1])
        l.pop()

    edges = set()
    for _ in range(m):
        a = choice(l)
        b = choice(r)
        if (a + 1, b + 1) in edges:
            continue
        edges.add((a + 1, b + 1))

    m = len(edges)
    print(edges, end=" ")

    return f"{n} {m}\n" + "\n".join(f"{a} {b}" for a, b in edges) + "\n"


def parse(s):
    s = s.splitlines()
    n, m = map(int, s[0].split())
    graph = [[] for _ in range(n)]
    for i in range(m):
        a, b = map(int, s[i + 1].split())
        a -= 1
        b -= 1
        graph[a].append(b)
        graph[b].append(a)

    return n, m, graph


def main():
    for _ in range(128):
        g = gen()
        Path('a.in').write_text(g)

        system('.\\a.exe < a.in > a.out')

        s = Path('a.out').read_text().splitlines()

        sol = solve(*parse(g))
        print(len(sol))

        def cmp():
            if not sol:
                return s[0].strip() == "NIE"
            return tuple(map(int, s[1].split())) in sol

        if not cmp():
            print("WOOOOO :<<<")
            print(sol)
            break


main()
