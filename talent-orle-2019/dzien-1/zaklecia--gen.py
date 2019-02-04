from random import *
from pathlib import *
from shutil import *


def gen(n=10):
    alphabet = "ab"
    s = ''.join(choice(alphabet) for _ in range(n))
    return f"1\n{s}\n"


p = Path('./zaklecia/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(256):
    (p / f'{i}.in').write_text(gen())
