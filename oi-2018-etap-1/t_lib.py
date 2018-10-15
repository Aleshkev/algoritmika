import os
from os import PathLike
from typing import *
import collections
import pathlib
import shutil
import re

__all__ = ['Pack']


class Pack:
    def __init__(self, task_path):
        self.folder = pathlib.Path(task_path)

        if not self.folder.is_dir():
            os.makedirs(self.folder)

        self.used_cases = collections.defaultdict(int)

        for f in self.folder.glob('*.in'):
            group, case = re.search(r'^([a-z]+)([0-9]+)\.in$', f.name).groups()
            self.used_cases[group] = max(self.used_cases[group], int(case))

        print(self.used_cases)

    def clear(self):
        shutil.rmtree(self.folder)
        self.folder.mkdir()

        self.used_cases.clear()

    def add(self, group: str, input_text: str, output_text: Optional[str] = None):
        case = self.used_cases[group]
        self.used_cases[group] += 1
        (self.folder / f'{group}{case}.in').write_text(input_text)
        if output_text is not None:
            (self.folder / f'{group}{case}.out').write_text(output_text)

    def solve_all(self, fn):
        for f in self.folder.glob('*.in'):
            answer = fn(f.read_text())
            f.with_suffix('out').write_text(answer)
