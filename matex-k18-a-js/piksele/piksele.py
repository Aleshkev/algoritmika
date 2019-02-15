from pathlib import Path


h, w = 200, 320


# file = Path('przyklad.txt')
file = Path('dane.txt')

data = tuple(tuple(map(int, s.split())) for s in file.read_text().splitlines())

min_value = min(min(x) for x in data)
max_value = max(max(x) for x in data)

print("max.:", max_value)
print("min.:", min_value)

unsymmetrical = sum(row != row[::-1] for row in data)

print("bez symetrii:", unsymmetrical)

contrasting = 0
for y, row in enumerate(data):
    for x, cell in enumerate(row):
        f = lambda x, y: (0 <= x < w and 0 <= y < h) and abs(data[y][x] - cell) > 128
        if f(x + 1, y) or f(x, y + 1) or f(x - 1, y) or f(x, y - 1):
            contrasting += 1

print("kontrastujące:", contrasting)

max_continuous = 0

for x, column in enumerate((data[y][x] for y in range(h)) for x in range(w)):
    continuous = 0
    current = -1
    for y, cell in enumerate(column):
        if cell != current:
            max_continuous = max(max_continuous, continuous)
            continuous = 0
            current = cell
        continuous += 1

print("blok:", max_continuous)
