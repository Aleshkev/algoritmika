def extended_euclidean(a, b):
    if a == 0: return b, 0, 1
    d, x, y = extended_euclidean(b % a, a)
    return d, y - (b // a) * x, x


a, b, m = map(int, input().split())
d, x, y = extended_euclidean(a, m)
if b % d == 0:
    r = m // d
    print((b // d * x % r + r) % r)
else:
    print("NIE")
