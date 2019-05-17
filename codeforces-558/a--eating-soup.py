n, m = map(int, input().split())

t = [True] * n
j = 0
for i in range(1, n, 2):
    if j == m:
        break
    t[i] = False
    j += 1

for i in range(n):
    if j == m:
        break
    if t[i]:
        t[i] = False
        j += 1

i = 0
c = 0
while i < n:
    if t[i]:
        c += 1
        while i < n and t[i]:
            i += 1
    else:
        i += 1
if t[0] and t[-1] and False in t:
    c -= 1
print(c)
