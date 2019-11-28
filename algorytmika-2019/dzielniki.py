import heapq

x = int(input())
sieve = [None] * (x + 1)
for i in range(2, x + 1):
    if sieve[i]: continue
    for j in range(i * i, x + 1, i):
        sieve[j] = i
primes = [i for i in range(2, x + 1) if sieve[i] is None]

v = primes.copy()


print(list(reversed(factorize(x))))
c = 1
for i, z in enumerate(reversed(factorize(x))):
    c *= primes[i] ** (z - 1)
print(c)
