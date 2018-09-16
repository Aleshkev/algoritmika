from random import *
import os, shutil

def answer(t, k):
    #u = [t[0]]
    #for i in range(1, len(t)):
    #    u.append(u[-1] + t[i])
    #def sumv(b, e):
    #    return (u[e - 1] if e > 0 else 0) - (u[b - 1] if b > 0 else 0)

    n = len(t)
    max_avg = 0.0
    for i in range(n - k + 1):
        for j in range(i + k, n + 1):
            max_avg = max(max_avg, sum(t[i:j]) / (j - i))
    return max_avg

def gen(n = 50):
    t = [randint(1, 10 ** 6) for _ in range(n)]
    k = randint(1, n)
    q = "{} {}\n{}\n".format(n, k, " ".join(map(str, t)))
    a = "{:.3f}\n".format(answer(t, k))
    return q, a

try:
    shutil.rmtree('./tests/')
except Exception as e:
    print("Ignoring:", e)
os.mkdir('./tests/')
for i in range(100):
    q, a = gen()
    with open('./tests/{}.in'.format(i), 'w') as f1:
        f1.write(q)
    with open('./tests/{}.out'.format(i), 'w') as f2:
        f2.write(a)
