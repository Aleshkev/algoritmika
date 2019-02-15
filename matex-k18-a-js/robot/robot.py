from pathlib import Path


n = 20
_board = [tuple(map(int, line.split())) for line in Path('plansza.txt').read_text().splitlines()]
board = [[_board[y][x] for y in range(n)] for x in range(n)]

moves_raw = [s for s in Path('robot.txt').read_text().splitlines()]
moves = [[{'N': (0, -1), 'E': (1, 0), 'S': (0, 1), 'W': (-1, 0)}[c] for c in s] for s in moves_raw]


disqualified = []
max_score = 0
max_score_players = []

for player_i, player_moves in enumerate(moves):
    x, y = 0, 0
    score = board[x][y]

    continuous = 0
    for delta in player_moves:
        x += delta[0]
        y += delta[1]

        if not (0 <= x < n and 0 <= y < n):
            score = -1
            disqualified.append(player_i)
            break
        score += board[x][y]
    if score > max_score:
        max_score = score
        max_score_players.clear()
    if score == max_score:
        max_score_players.append(player_i)


max_continuous = 0
max_continuous_players = []


for player_i, player_moves in enumerate(moves):
    continuous = 0
    for delta in player_moves:
        if delta[1] == 0:
            continuous += 1
            if continuous > max_continuous:
                max_continuous = continuous
                max_continuous_players.clear()
            if continuous == max_continuous:
                max_continuous_players.append(player_i)
        else:
            continuous = 0


def inc(v):
    return [i + 1 for i in v]


print("zdyskwalifikowanych:", len(disqualified))
print("max. wynik:", max_score, inc(max_score_players))
print("max. ruchy w wierszy:", max_continuous, inc(max_continuous_players))
