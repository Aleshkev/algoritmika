from random import *
from pathlib import *
from os import *


def gen(n=20, m=5):
    t = [randint(1, 10) for _ in range(n)]
    q = []
    for _ in range(m):
        if random() < 0.5:
            q.append(f"podlej {randint(1, n)}")
        else:
            a = randint(1, n)
            q.append(f"zbieraj {a} {randint(a, n)}")
    return f"{n} {m}\n" + " ".join(map(str, t)) + "\n" + "\n".join(q)


args = "g++ -std=c++11 -Wall -O2"
system(args + " jablonie--alpha.cpp -o a.exe")
system(args + " jablonie--beta.cpp -o b.exe")

for i in range(1000):
    g = gen()
    Path("test.in").write_text(g)

    system("a.exe < test.in > a.out")
    system("b.exe < test.in > b.out")

    a = Path("a.out").read_text().strip()
    b = Path("b.out").read_text().strip()

    if a == b:
        print(f"{i}: ok")
    else:
        print(f"{i}: no ok\n---\n{g}\n---")
        print(repr(a), repr(b))
