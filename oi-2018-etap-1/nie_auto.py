import subprocess
import io
import tempfile

import nie

program = './a.exe'

for i in range(100000 + 1):
    a, b = nie.gen()

    in_file = tempfile.NamedTemporaryFile('w+')
    in_file.write('\n'.join([a, b]))
    in_file.seek(0)

    out_file = tempfile.NamedTemporaryFile('w+')
    p = subprocess.call([program], stdin=in_file, stdout=out_file)
    in_file.seek(0)
    out_file.seek(0)

    r = out_file.read().splitlines()[0].strip()  # Yes, it ignores all the lines except the first.

    status, reason = nie.check_solution(a, b, r)

    if status:
        print(".", end="")
        if i % 100 == 0:
            print(i)
    else:
        print()
        print("--- WRONG ANSWER ---")
        print(a)
        print(b)
        print(reason)
        print("--- brought to you by Aleshkevich Interactive ---")
print()
