
p = 10 ** 9 + 7


def sum_even(n):
    return n * (n + 1) % p if n > 0 else 0


def sum_odd(n):
    return (n + sum_even(n - 1)) % p if n > 0 else 0


def sum_special(n):
    if n < 1:
        return 0
    d = 1
    i = 0
    s = [0, 0]
    k = 0
    while i < n:
        s[k] += min(d, n - i)
        k = (k + 1) % 2
        i += d
        d *= 2
    return (sum_odd(s[0]) + sum_even(s[1])) % p


l, r = map(int, input().split())

print((p + sum_special(r) - sum_special(l - 1)) % p)
