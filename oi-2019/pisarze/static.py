from common import *

words = [list(filter(lambda x: x, map(preprocess_word, Path(s).read_text().split()))) for s in
         ["Mickiewicz.txt", "Sienkiewicz.txt", "Prus.txt"]]
global_words = list(chain(*words))

unique_words = [set(words[i]) for i in range(3)]
global_unique_words = set(global_words)

word_counts = [Counter(words[i]) for i in range(3)]
global_word_counts = {k: sum(word_counts[i][k] for i in range(3)) for k in global_unique_words}

word_frequencies = [{k: word_counts[i][k] / global_word_counts[k] for k in global_unique_words} for i in range(3)]


def judge(s: str):
    x = global_word_counts[s]
    a, b, c = (word_frequencies[i][s] for i in range(3))
    d = max(map(abs, (a - b, b - c, a - c)))
    return x if d > 0.9 else 0


best_words = sorted(global_unique_words, key=judge, reverse=True)

for s in best_words[:100]:
    c = " ".join(f"{round(word_frequencies[i][s], 5):<8}" for i in range(3))
    print(f"{s:>20} {str(judge(s)):<25} | {c}")


r = []

to_save = []
for s in best_words[:2050]:
    z = [0] * 3
    for i in range(3):
        p = int(word_frequencies[i][s] * (256 ** 1 - 1))
        if p == 0 and word_frequencies[i][s] > 0: p = 1
        z[i] = p
    to_save.append((s, *z))

for s, a, b, c in sorted(to_save, key=lambda x: (*x[1:], x[0])):
    r.append(int(s).to_bytes(3, "big"))
    r.append(a.to_bytes(1, "big"))
    r.append(b.to_bytes(1, "big"))
    r.append(c.to_bytes(1, "big"))

data = compress(b"".join(r)).decode()
print(len(data))
Path("data.txt").write_text(data)
