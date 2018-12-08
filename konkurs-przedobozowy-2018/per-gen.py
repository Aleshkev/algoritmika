from random import *
from pathlib import *
from shutil import *

p = Path('./per/')
try:
    rmtree(p)
except FileNotFoundError:
    pass
p.mkdir()


def gen(n):
    t = [i + 1 for i in range(n)]
    shuffle(t)
    return f'{n}\n{" ".join(map(str, t))}\n'


for i in range(256):
    (p / f'{i}.in').write_text(gen(10))
