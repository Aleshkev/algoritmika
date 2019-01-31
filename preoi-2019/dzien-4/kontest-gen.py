from random import *
from pathlib import *
from shutil import *


def gen(n=10, m=10, t=10):
    o = []
    for _ in range(m):
        o.append(f"{randint(1, n)} {randint(1, t)} {randint(0, 10) * 10}")
    return f"{n} {m} {t}\n" + '\n'.join(o)


p = Path('./draft/kontest/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(512):
    (p / f'{i}.in').write_text(gen())
