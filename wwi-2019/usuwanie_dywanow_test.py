from random import *
from pathlib import *
from os import *


def gen(n=10, m=10):
    l = [[n, m]]
    for _ in range(n):
        x, y = randint(1, m), randint(1, m)
        l.append([x, randint(x, m), y, randint(y, m)])

    return "\n".join(" ".join(map(str, line)) for line in l)


args = "g++ -std=c++11 -Wall -O2"
system(args + " usuwanie-dywanow--alpha.cpp -o a.exe")
system(args + " usuwanie-dywanow--beta.cpp -o b.exe")

for i in range(10000):
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
