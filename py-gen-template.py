from random import *
from pathlib import *
from shutil import *


def gen(n=10):
    return ""


p = Path('./draft/xyz/')
if p.is_dir():
    rmtree(p)
p.mkdir(parents=True)

for i in range(256):
    (p / f'{i}.in').write_text(gen())
