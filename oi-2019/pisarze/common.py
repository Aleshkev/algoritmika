import string
from typing import *
from pathlib import *
from itertools import *
from collections import *
import zlib


def preprocess_word(s: str):
    return str(hash_to_bytes("".join(c.lower() for c in s if c in string.ascii_letters)))


alphabet = b"abcdefghijklmnopqrstuvwxyz!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`{|}~"


def compress(s: bytes):
    s = zlib.compress(s, 9)
    d = 0
    for c in s:
        d = (256 * d) + c
    z = []
    while d > 0:
        z.append(alphabet[d % len(alphabet)])
        d //= len(alphabet)
    return bytes(z[::-1])


def decompress(s: bytes):
    d = 0
    for c in s:
        d = (len(alphabet) * d) + alphabet.index(c)
    z = []
    while d > 0:
        z.append(d % 256)
        d //= 256
    return zlib.decompress(bytes(z[::-1]))


def hash_to_bytes(s: str, n = 3):
    h = 0
    for c in s:
        h *= 29
        h += (string.ascii_lowercase + string.digits).index(c)
    return h % (256 ** n)


def chunks(l, n):
    for i in range(0, len(l), n):
        yield l[i:i + n]
