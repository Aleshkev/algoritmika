from math import ceil

n, t = map(int, input().split())

route, best_c = 0, 10**8

for i in range(n):
    s, d = map(int, input().split())
    c = (s + d * ceil((t - s) / d)) if t > s else s
    if c < best_c:
        route = i
        best_c = c

print(route + 1)
