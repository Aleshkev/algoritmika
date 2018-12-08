from random import *
from pathlib import *
from shutil import *


def gen(n):
    m = randint(2, 2 * n)
    t = [randint(1, m) for _ in range(n)]
    return f'{n} {m}\n{" ".join(map(str, t))}\n'


p = Path('./jas/')
try:
    rmtree(p)
except FileNotFoundError:
    pass
p.mkdir()

for i in range(256):
    (p / f'{i}.in').write_text(gen(10))
