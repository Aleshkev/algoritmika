import os, sys
from pathlib import *
import dynamic

group = sys.argv[1]


def single_test():
    os.system(f"testgen.py {group}")
    inp = Path("a.in").read_text()
    outp = Path("a.out").read_text()

    os.system(f"release2.py < a.in > b.out")
    poutp = Path("b.out").read_text()

    # poutp = dynamic.solve(inp)

    ok, all = 0, 0
    for a, b in zip(outp.splitlines(), poutp.splitlines()):
        if a == b.split()[0]:
            ok += 1
        all += 1
    return ok, all


def score(p, t):
    if p >= .9 * t: return 100
    if p <= t / 3: return 0
    return 100 * (p - t/3) / (.9 * t - t / 3)


avg = 0
avg_s = 0
for i in range(15):
    a, b = single_test()
    s = score(a, b)
    print(f"{a}/{b} = {round(a / b * 100, 1)}% -> {round(s, 1)}p")
    avg = (avg * i + a / b) / (i + 1)
    avg_s = (avg_s * i + s) / (i + 1)
print(f"average: {round(avg * 100, 1)}% -> {round(avg_s, 1)} p")
