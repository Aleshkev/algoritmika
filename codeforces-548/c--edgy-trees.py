import collections

p = 10 ** 9 + 7
n, k = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b, x = map(int, input().split())
    if x != 0:
        continue
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)

v = [False] * n
bad = 0
for i in range(n):
    if v[i]:
        continue

    d = collections.deque()
    d.append(i)
    v[i] = True
    c = 0
    while d:
        i = d.pop()
        for j in g[i]:
            if v[j]:
                continue
            v[j] = True
            d.append(j)
        c += 1
    bad += pow(c, k, p)
print((pow(n, k, p) + p - bad) % p)
