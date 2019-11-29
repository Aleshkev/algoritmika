import os
from pathlib import *


for w in range(1, 11):
    for h in range(1, 11):
        for k in range(1, w * h + 3):
            Path("a.in").write_text(f"{w} {h} {k}\n")
            os.system(f"..\\a.exe < a.in > a.out")
            out = Path("a.out").read_text()
            if "ERR" in out:
                x = out.find("ERR")
                print(f"{w:<3} {h:<3} {k:<3}:", out[x:out.find("\n", x)])
