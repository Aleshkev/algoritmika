# release2.py to ten plik, tylko zminifikowany.

from zlib import *

A = "abcdefghijklmnopqrstuvwxyz!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`{|}~"


def d(s):
    d, r = 0, []
    for c in s: d = len(A) * d + A.index(c)
    while d > 0:
        r.append(d % 256)
        d //= 256
    return decompress(bytes(r[::-1]))


def h(s):
    h = 0
    for c in s: h = h * 29 + A.index(c)
    return h % (256 ** 3)


def w(s):
    return h("".join(c for c in s.lower() if c in A[:27]))


def m(l, n):
    for i in range(0, len(l), n): yield l[i:i + n]


z = d(__import__("pathlib").Path("data.txt").read_text())
t = {}
for l in m(z, 6):
    s, *x = (int.from_bytes(l[x:y], "big") for x, y in ((0, 3), (3, 4), (4, 5), (5, 6)))
    t[s] = (*x,)
n = int(input())
for _ in range(n):
    l = [x for x in map(w, input().split()) if x]
    r = [1] * 3
    for s in l:
        if s in t:
            r = [r[0] * t[s][0], r[1] * t[s][1], r[2] * t[s][2]]
    x = r.index(max(r))
    print(["Mickiewicz", "Sienkiewicz", "Prus"][x])
