X = int(input())
now, turn = 0, 0
while now < X:
    now += turn + 1
    turn += 1
print(turn)
