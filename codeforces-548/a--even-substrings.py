n, s = int(input()), input().strip()

c = 0
for i in range(n):
    if int(s[i]) % 2 == 0:
        c += i + 1
print(c)
