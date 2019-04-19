for i in range(10 ** 6):
    n, m = map(int, input().split())
    if n == m == 0:
        break
    for _ in range(n):
        input()
    p = []
    for j in range(m):
        n = input()
        d, r = input().split()
        d = float(d)
        r = int(r)
        for _ in range(r):
            input()
        p.append((n, d, r, j))
    p.sort(key=lambda v: (-v[2], v[1], v[3]))
    if i > 0:
        print()
    print("RFP #{}".format(i + 1))
    print(p[0][0])