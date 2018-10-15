import random

from t_lib import *


alphabet = 'abcd'


def _gen_ok(a, b):
    for i in a:
        if i in b:
            return True
    return False


def gen(n=10, m=10, r=random):
    a = b = ''
    while not _gen_ok(a, b):
        a = ''.join(r.choice(alphabet) for _ in range(n))
        b = ''.join(r.choice(alphabet) for _ in range(m))
    return f'{a}\n{b}\n'


def is_sub_seq(x, y):
    """Test whether x is a subsequence of y"""
    x = list(x)
    for letter in y:
        if x and x[0] == letter:
            x.pop(0)

    return not x


def check_solution(a, b, r):
    for i in range(len(r) + 1):
        for c in alphabet:
            extended = r[:i] + c + r[i:]
            if is_sub_seq(extended, a) and is_sub_seq(extended, b):
                return False, extended
    return True, None


check_solution("abcda", "abcda", "ac")


f = Pack('draft/nie')
f.clear()

for x in range(10):
    f.add('a', gen())
