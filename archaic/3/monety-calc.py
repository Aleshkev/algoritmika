s = 11

t = []

for a in range(0, s + 1):
    for b in range(0, s - a + 1):
        c = s - a - b
        t.append((a, b, c))

t = list(set(t))
t.sort()

for a, b, c in t:
    print(a, b, c)

print(len(t))
