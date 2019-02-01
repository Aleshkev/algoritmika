from random import *
from pathlib import *
from shutil import *
from string import *


def gen(n=10, k=4):
    return "".join(choice(ascii_lowercase[:6]) for _ in range(n)) + f"\n{k}\n"


p = Path('./literki/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(256):
    (p / f'{i}.in').write_text(gen())
