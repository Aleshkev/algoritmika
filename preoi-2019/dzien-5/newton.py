p = 10 ** 9 + 7


division = 10 ** 5
factorial_table = []  # Tutaj wkleić listę wypisaną przez newton--preprocessing.cpp


def factorial(n):
    c = factorial_table[n // division]
    for i in range(n - n % division + 1, n + 1):
        c = c * i % p
    return c


def inv(n):
    return pow(n, p - 2, p)


def f(n, k):
    def symbol(n, k):
        if 0 <= k <= n:
            return factorial(n) * inv(factorial(k)) % p * inv(factorial(n - k)) % p
        else:
            return 0

    c = 1
    while n > 0:
        c = c * symbol(n % p, k % p) % p
        n //= p
        k //= p
    
    return c


n, k = map(int, input().split())
print(f(n, k))
