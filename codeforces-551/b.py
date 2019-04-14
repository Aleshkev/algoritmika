n, m, h = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
t = [list(map(int, input().split())) for y in range(n)]

u = [[0] * m for _ in range(n)]
for y in range(n):
    for x in range(m):
        u[y][x] = min(a[x], b[y]) * t[y][x]

print("\n".join(" ".join(map(str, i)) for i in u))

