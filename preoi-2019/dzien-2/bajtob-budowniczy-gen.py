from random import *
from pathlib import *
from shutil import *


def gen(n=16, m=10):
    z = map(str, (randint(0, 10) for _ in range(n)))
    o = []
    for i in range(m):
        a = randrange(0, n)
        b = randrange(a, n)
        if random() < 0.5:
            o.append(f"0 {a + 1} {b + 1} {randint(0, 10)}")
        else:
            o.append(f"1 {a + 1} {b + 1}")
    return f"{n} {m}\n" + ' '.join(z) + '\n' + '\n'.join(o)


p = Path('./draft/bajt/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(512):
    (p / f'{i}.in').write_text(gen())
