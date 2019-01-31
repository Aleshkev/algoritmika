from random import *
from pathlib import *
from shutil import *


def gen(n=500, m=10):
    o = [randint(1, m) for _ in range(n)]
    return f"{n} {m}\n" + " ".join(map(str, o)) + "\n"


p = Path('./remis/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(256):
    (p / f'{i}.in').write_text(gen())
