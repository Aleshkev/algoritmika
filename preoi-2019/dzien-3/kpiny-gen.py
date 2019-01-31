from random import *
from pathlib import *
from shutil import *


def gen(n=10):
    o = []
    for i in range(1, n):
        o.append(f"{randrange(0, i) + 1} {i + 1}")
    return f"{n}\n" + '\n'.join(o) + '\n'


p = Path('./draft/kpiny/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(256):
    (p / f'{i}.in').write_text(gen())
