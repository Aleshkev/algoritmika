def check_composite(n, a, d, s):
    x = pow(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for r in range(1, s):
        x = x ** 2 % n
        if x == n - 1:
            return False
    return True


def is_prime(n):
    if n == 1: return False
    s, d = 0, n - 1
    while d % 2 == 0:
        d, s = d // 2, s + 1

    for a in filter(lambda i: i < n, [2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37]):
        if check_composite(n, a, d, s):
            return False
    return True


for _ in range(int(input())):
    x = int(input())
    print("TAK" if is_prime(x) else "NIE")
