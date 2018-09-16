from random import *
import os

def answer(t, k):
    n = len(t)
    max_s = 0
    for i in range(n - k + 1):
        for j in range(i + k, n + 1):
            max_s = max(max_s, sum(t[i:j]))
    return max_s

def gen(n=100):
    t = [randint(-50, 100) for _ in range(n)]
    k = randint(1, n)
    q = "{} {}\n{}".format(n, k, " ".join(map(str, t)))
    a = "{}\n".format(answer(t, k))
    return q, a

try:
    os.rmdir('./tests/')
except Exception as e:
    print(e)
os.makedirs('./tests/')
for i in range(100):
    q, a = gen()
    with open('./tests/{}.in'.format(i), 'w') as f1:
        f1.write(q)
    with open('./tests/{}.out'.format(i), 'w') as f2:
        f2.write(a)

