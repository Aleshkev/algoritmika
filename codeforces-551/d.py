n = int(input())
f = tuple(map(int, input().split()))

tree = [[] for _ in range(n)]
for i, parent in zip(range(1, n + 1), map(lambda x: int(x) - 1, input().split())):
    tree[parent].append(i)

d = [0] * n

leaves = 0
for i in reversed(range(n)):
    if not tree[i]:
        d[i] = 1
        leaves += 1
        continue
    if f[i] == 0:
        d[i] = sum(d[j] for j in tree[i])
    else:
        d[i] = min(d[j] for j in tree[i])

print(leaves - d[0] + 1)
