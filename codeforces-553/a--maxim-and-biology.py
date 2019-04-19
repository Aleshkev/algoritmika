input()
s = input()
n = len(s)

a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def f(x, y):
    x, y = min(x, y), max(x, y)
    return min(a.index(y) - a.index(x), a.index(x) + len(a) - a.index(y))


z = 10**18
for i in range(n - 4 + 1):
    c = f(s[i], "A") + f(s[i + 1], "C") + f(s[i + 2], "T") + f(s[i + 3], "G")
    z = min(z, c)

print(z)
