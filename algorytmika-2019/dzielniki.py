n = int(input())

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89]

lim = 10 ** 14

d = [lim for i in range(n + 1)]
d[1] = 1
for p in primes:
    t = d.copy()
    for i in range(n + 1):
        for k in range(0, lim):
            if i * (k + 1) > n or d[i] * pow(p, k) > lim:
                break
            t[i * (k + 1)] = min(t[i * (k + 1)], d[i] * pow(p, k))
    d = t

print(d[n])
