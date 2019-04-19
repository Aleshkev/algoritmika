n, m = map(int, input().split())

t = [list(map(int, input().split())) for _ in range(n)]

for i in range(10):
    m = (1 << i)

    is_zero = [all(i & m == 0 for i in row) for row in t]
    is_one = [all(i & m != 0 for i in row) for row in t]

    zero = is_zero.count(True)
    one = is_one.count(True)

    needed = 1 - one % 2
    ok = n - zero - one >= needed
    if not ok:
        continue

    print("TAK")
    for y, row in enumerate(t):
        if is_zero[y] or is_one[y]:
            print(1, end=" ")
            continue
        for i, e in enumerate(row):
            if needed and e & m != 0:
                print(i + 1, end=" ")
                needed -= 1
                break
            elif not needed and e & m == 0:
                print(i + 1, end=" ")
                break
    break
else:
    print("NIE")

