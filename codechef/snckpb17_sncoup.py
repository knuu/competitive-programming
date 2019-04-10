for _ in range(int(input())):
    N = int(input())
    row1 = input()
    row2 = input()
    ans = int(row1.count('*') > 0 and row2.count('*') > 0)
    snakes = []
    for i, c in enumerate(row1):
        if c == '*':
            snakes.append((i, 0))
    for i, c in enumerate(row2):
        if c == '*':
            snakes.append((i, 1))
    if len(snakes) <= 1:
        print(0)
        continue
    snakes.sort(reverse=True)
    prev = snakes.pop()
    now = snakes.pop()
    while snakes:
        ans += 1
        if prev[1] == now[1]:
            prev, now = now, snakes.pop()
        else:
            if now[0] == snakes[-1][0]:
                prev, now = now, snakes.pop()
            elif len(snakes) <= 1:
                break
            else:
                prev = snakes.pop()
                now = snakes.pop()
    else:
        ans += prev[1] == now[1]
    print(ans)
