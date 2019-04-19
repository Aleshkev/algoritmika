seq = {
    'y': ['+x', '+y', '-x', '-y'],
    'z': ['+x', '+z', '-x', '-z']
}

while True:
    n = int(input())
    if n == 0:
        break
    state = '+x'
    for move in input().split():
        if move == "No":
            continue
        if {move[1], state[1]} == {'y', 'z'}:
            continue
        s = seq[move[1]]
        state = s[(4 + s.index(state) + int(move[0] + '1')) % 4]
    print(state)
