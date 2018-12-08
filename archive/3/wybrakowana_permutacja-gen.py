from random import *
from itertools import *

def g(n = 10):
    t = list(range(1, n + 1))
    shuffle(t)
    s = randint(0, n)
    t[0:s] = [0] * s
    shuffle(t)
    return "{}\n{}".format(n, " ".join(map(str, t)))

for i in range(100):
    if True:
        with open("test" + str(i) + ".p.out", 'r') as f:
            s = f.readlines()
            print(s[0].strip(), s[1].strip())
    else:
        with open("test" + str(i) + ".in", 'w') as f:
            f.write(g())
        
