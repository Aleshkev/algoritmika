import random


def gen_tests(n=20, m=None):
    if m is None:
        m = random.randrange(1, n * n)
    possible_connections = []
    for a in range(1, n + 1):
        for b in range(a + 1, n + 1):
            possible_connections.append((a, b))
    random.shuffle(possible_connections)

    print(possible_connections)

    connections = possible_connections[:m]
    connections.sort()

    return f"{n} {m}\n{'  '.join(f'{a} {b}' for a, b in connections)}"

for _ in range(0):
    print(gen_tests(20, 40))


from io import *
from subprocess import *
from tempfile import *

A = r"..\ladunki_dobrego\bin\Debug\ladunki_dobrego.exe"
B = r"..\ladunki\bin\Debug\ladunki.exe"

t = gen_tests(5)
in_ab = TemporaryFile()
in_ab.write(t.encode('utf-8'))
in_ab.seek(0)
out_a = TemporaryFile()
call(A, stdin=in_ab, stdout=out_a)
in_ab.seek(0)
out_b = TemporaryFile()
call(B, stdin=in_ab, stdout=out_b)

in_ab.seek(0)
out_a.seek(0)
out_b.seek(0)

print(in_ab.read())
s_out_a = out_a.read()
s_out_b = out_b.read()
print(s_out_a, s_out_b)
if(s_out_a != s_out_b):
    print("INVALID\n", t, "\nA:", s_out_a, "\nB:", s_out_b)
else:
    print("Match :D")
