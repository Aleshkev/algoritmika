from random import *
from pathlib import *
from os import *


def gen(n=5, m=5):
    return f"{n}\n" + "\n".join(" ".join(map(str, (randint(-m, +m), randint(-m, +m)))) for _ in range(n))


args = "g++ -std=c++11 -Wall -O2"
system(args + " talon--alpha.cpp -o a.exe")
system(args + " talon--beta.cpp -o b.exe")

for i in range(100):
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
