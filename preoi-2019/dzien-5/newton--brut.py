from math import factorial


def f(n, k, p=10**9 + 7):
    c = 1
    for i in range(k):
        c *= n - i
    return c // factorial(k) % p

n, k = map(int, input().split())
print(f(n, k))
