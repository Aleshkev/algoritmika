from random import *

def gen(n = 6):
    t = list(range(1, n + 1))
    shuffle(t)

    return " ".join(map(str, [n, randint(1, n * n)] + t))

from shutil import *
from os import *
from builtins import *
try:
    rmtree("./tests/")
except:
    print("nodirdel")
mkdir("./tests/")
for i in range(100):
    with open("./tests/t{}.in".format(i), 'w') as f:
        f.write(gen())
print("done")
