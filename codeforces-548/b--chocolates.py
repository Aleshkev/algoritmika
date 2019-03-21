n = int(input())
t = list(map(int, input().split()))

v = [0] * n
v[-1] = t[-1]
for i in range(n - 1 - 1, 0 - 1, -1):
    v[i] = max(min(v[i + 1] - 1, t[i]), 0)

print(sum(v))
