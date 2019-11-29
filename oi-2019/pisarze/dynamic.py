from common import *


data = decompress(Path("data.txt").read_text().encode())
weights = {}
for line in chunks(data, 6):
    s = str(int.from_bytes(line[0:3], "big"))
    a = int.from_bytes(line[3:4], "big")
    b = int.from_bytes(line[4:5], "big")
    c = int.from_bytes(line[5:6], "big")
    weights[s] = (a, b, c)


def solve_one(s: str):
    words = list(filter(lambda x: x, map(preprocess_word, s.split())))
    r = [1] * 3
    for s in words:
        if s in weights:
            a, b, c = weights[s]
            r[0] *= a
            r[1] *= b
            r[2] *= c
    z = r.index(max(r))
    return {0: "Mickiewicz", 1: "Sienkiewicz", 2: "Prus"}[z]


def solve(s):
    return "".join(f"{solve_one(line)}\n" for line in s.splitlines()[1:])


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        l = input()
        print(solve_one(l))
