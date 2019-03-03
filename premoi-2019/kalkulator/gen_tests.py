from typing import *
import collections
import pathlib
import shutil
import string
import random
import re
import sys
import subprocess
import tempfile


def overflow(s: str, n: int = 128):
    if len(s) > n:
        return s[:n - 3] + "..."
    return s


def perfect_solve(s: str):
    class X(int):
        def __add__(self, other):
            return X((int(2 * self) + other) % (10 ** 9 + 7))

    e = s.replace('#', '+')
    e = re.sub("([0-9]+)", r"X(\1)", e)
    return str(eval(e))


def quick_solve(s: str):
    c = subprocess.run("../../a.exe", input=s, capture_output=True, text=True)
    return c.stdout


def refresh(path: pathlib.Path):
    if path.is_dir():
        shutil.rmtree(path)
    path.mkdir()


in_folder = pathlib.Path('./in/')
out_folder = pathlib.Path('./out/')

refresh(in_folder)
refresh(out_folder)


used = collections.defaultdict(lambda: 0)


def add(group: int, in_str: str, out_str: Optional[str] = None, out_fn: Optional[Callable[[str], str]] = quick_solve):
    in_str = in_str + '\n'

    if out_str:
        o = out_str
    else:
        o = out_fn(in_str)

    x = string.ascii_lowercase[used[group]]
    (in_folder / f"klk{group}{x}.in").write_bytes(in_str.encode('ascii'))
    (out_folder / f"klk{group}{x}.out").write_bytes(o.encode('ascii'))

    print(overflow(repr(in_str)), f"[{len(in_str)}]", overflow(repr(o)))

    used[group] += 1


add(0, "1 # 1")
add(0, "1 # 1 # 1 # 1")
add(0, "(1 # 1) # (1 # 1)")
add(0, " # ".join(["2"] * 30))


def generate(n: int = 10, m: int = 5, r: range = range(0, 10), long=False):
    paren_before, paren_after = collections.defaultdict(int), collections.defaultdict(int)
    for _ in range(m):
        x = random.randrange(0, n)
        paren_before[x] += 1
        paren_after[random.randrange(x, n)] += 1

    s = []
    l = [random.randrange(r.start, r.stop) for _ in range(n)]
    for i, e in enumerate(l):
        s.append("(" * paren_before[i])
        s.append(str(e))
        s.append(")" * paren_after[i])
        if i < n - 1:
            s.append(" # " if long else "#")
    return "".join(s)


random.seed("Determinism.")

# 2^n
for _ in range(20):
    add(1, generate(10, 10, long=True))

# ~n^2
for _ in range(8):
    add(2, generate(10**3, 10**3, range(0, 10 ** 9 + 7)))

for _ in range(8):
    add(2, generate(10**4, 10**4, range(0, 10**100)))

for _ in range(8):
    add(2, generate(10**5, 10**4, range(1, 10*18)))

# n
for _ in range(8):
    add(3, generate(10**3, 10**6 - 10**3))

for _ in range(8):
    add(3, generate(10**6 - 10**2, 10**2))

# Długość dokładnie 2 * 10**6
add(3, ''.join(random.choice(string.digits[1:]) for _ in range(2 * 10**6)))

# Maksymalny poziom zagnieżdżenia
add(3, '(' * (10**6 - 1) + '1' + ')' * (10 ** 6 - 1))


def auto_config(memory: int = 131072, time: int = 2000):
    s = ["title: Kalkulator", "memory_limits:"]
    for i in range(10):
        for j in range(used[i]):
            s.append(f"    {i}{string.ascii_lowercase[j]}: {memory}")

    s.append("time_limits:")
    for i in range(10):
        for j in range(used[i]):
            s.append(f"    {i}{string.ascii_lowercase[j]}: {time}")
    s += ["points:", "    1: 20", "    2: 20", "    3: 60"]
    return "\n".join(s)


pathlib.Path('config.yml').write_text(auto_config())
