n = int(input())
s = input()


def f():
    level = 0
    blank = 0
    filled = []

    for i, c in enumerate(s):
        if c == "(":
            level += 1
        elif c == ")":
            level -= 1
            if level < 0:
                if blank < 0:
                    return
                filled.append("(")
                blank -= 1
                level += 1
        else:
            blank += 1
    filled_rev = []
    while level > 0:
        if blank < 0:
            return
        filled_rev.append(")")
        blank -= 1
        level -= 1

    if blank % 2 != 0:
        return

    while blank > 0:
        filled.append("(")
        filled_rev.append(")")
        blank -= 2

    f = filled + filled_rev[::-1]

    z = list(s)
    j = 0
    for i, c in enumerate(s):
        if c == "?":
            z[i] = f[j]
            j += 1

    l = 0
    for i, c in enumerate(z):
        if c == "(":
            l += 1
        else:
            l -= 1
        if l == 0 and i != n - 1:
            return
    if l != 0:
        return

    return "".join(z)


# def g():
#     m = []
#     for filled in product("()", repeat=s.count("?")):
#         z = list(s)
#         j = 0
#         for i, c in enumerate(s):
#             if c == "?":
#                 z[i] = filled[j]
#                 j += 1
#         z = "".join(z)
#
#         l = 0
#         for i, c in enumerate(z):
#             if c == "(":
#                 l += 1
#             else:
#                 l -= 1
#             if l <= 0 and i != n - 1:
#                 break
#             if i == n - 1 and l != 0:
#                 break
#         else:
#             print(z)
#             m.append(z)
#     return m

z = f()
print(z if z else ":(")
