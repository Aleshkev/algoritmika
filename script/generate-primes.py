from pathlib import Path
from sympy import nextprime

s = []
s.append("| `10`<sup>`n` | Primes |")
s.append("| :--- | :--- |")
for i in range(3, 40):
    p = "<br>".join(f"`{nextprime(10 ** (i - 1), j)}`" for j in range(1, 10 + 1))
    s.append(f"| `10`<sup>`{i}` | {p} |")
z = "\n".join(s)

(Path(__file__).parents[1] / 'primes.md').write_text(z)
