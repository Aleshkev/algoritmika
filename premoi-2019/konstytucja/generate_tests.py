from typing import *
import re
import random
import string
import subprocess
import pathlib
import shutil
import collections


def overflow(s: str, n: int = 128):
    if len(s) > n:
        return s[:n - 3] + "..."
    return s


def solve(s: str):
    s = re.sub(r"""[?!.;'"&()]""", ' ', s)  # AFAIK, ten regex jest liniowy.
    r = []
    for line in s.splitlines():
        line = line.strip()
        if not line:
            continue
        x = line.split()
        r.append(f"{min(x, key=lambda k: k.lower())} {max(x, key=lambda k: k.lower())}")
    return '\n'.join(r)


def ext_solve(s: str):
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


def add(group: int, in_str: str, out_str: Optional[str] = None, out_fn: Optional[Callable[[str], str]] = ext_solve):
    if out_str:
        o = out_str
    else:
        o = out_fn(in_str)

    x = string.ascii_lowercase[used[group]]
    (in_folder / f"kon{group}{x}.in").write_text(in_str)
    (out_folder / f"kon{group}{x}.out").write_text(o)

    print(overflow(repr(in_str)), f"[{len(in_str)}]", overflow(repr(o)))

    used[group] += 1


def word_generator(length: Iterable = range(1, 5)):
    return lambda: ''.join(random.choice(string.ascii_letters) for _ in range(random.choice(length)))


def biased_word_generator(length: int = 50, all_same: int = 0):
    return lambda: (str(random.choice(string.ascii_letters)) * all_same +
                    ''.join(random.choice(string.ascii_letters) for _ in range(length - all_same)))


def generate(n: int = 10, m: int = 100, word=word_generator()):
    lines = [[word()] for _ in range(n)]
    for _ in range(m - n):
        random.choice(lines).append(word())
    return '\n'.join(random.choice(" ?!.;'\"&() ").join(line) for line in lines) + '\n'


random.seed("Determinism.")


for f in pathlib.Path().glob('0*.in'):
    add(0, f.read_text())

# Proste testy poprawnościowe, nwm czy dobrej jakości.
for i in range(26):
    add(1, generate(i + 15, 5 * (i + 15)))

for i in range(4):
    add(2, generate(10 ** 3, 10 ** 4 // 5, word_generator(range(400, 500 + 1))))

# Żeby nie dało się porównywać np. tylko pierwszych 20 znaków wejścia (inne testy są generowane w taki sposób, że to
# przechodzi).
for i in range(2):
    add(2, generate(10**2, 10**3, biased_word_generator(900, all_same=800)))
add(2, generate(5, 10**2, biased_word_generator(10 ** 6 // 10**2 - 1, 10 ** 6 // 10**2 - 20)))

# Jakieś tam skrajne przypadki.
add(2, generate(10 ** 6 // 2, 10 ** 6 // 2, word_generator([1])))
add(2, generate(1, 1, word_generator([10 ** 6 - 1])))


def auto_config(memory: int = 131072, time: int = 2000):
    s = ["title: Konstytucja", "memory_limits:"]
    for i in range(10):
        for j in range(used[i]):
            s.append(f"    {i}{string.ascii_lowercase[j]}: {memory}")

    s.append("time_limits:")
    for i in range(10):
        for j in range(used[i]):
            s.append(f"    {i}{string.ascii_lowercase[j]}: {time}")
    s += ["points:", "    1: 20", "    2: 80"]
    return "\n".join(s)


pathlib.Path('config.yml').write_text(auto_config())
