from random import *
import os

def f(n, k):
    return n - k * (k - 1) // 2 >= k

def ans(s):
    return "TAK" if f(*(int(i) for i in s.split())) else "NIE"

def f2(n, k):
    def qmul(a, b):
        if a == 1:
            return b
        c = b * (a % 2) + qmul(a // 2, b) * 2
        print(a, b, c)
        if c > 2 * n:
            raise nie
        return c
    qmul(k, k - 3)
    raise tak


def tgen(fp):
    inn = fp + '.in'
    out = fp + '.out'

    s = "{} {}\n".format(randint(1, 10 ** 18), randint(1, 10 ** 18))
    with open(inn, 'w') as f:
        f.write(s)
    with open(out, 'w') as f2:
        f2.write(ans(s) + '\n')
os.makedirs('./cukierki_testy', exist_ok=True)
for i in range(1024):
    tgen('./cukierki_testy/x{}'.format(i))
    
