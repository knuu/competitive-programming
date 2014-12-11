while True:
    n = int(input())
    if n == 0: break
    step = input().split()
    ans = 0
    for i in range(0, len(step), 2):
        if i+1 == len(step): break
        if (step[i] == 'lu' and step[i+1] == 'ru') or (step[i] == 'ru' and step[i+1] == 'lu') or (step[i] == 'ld' and step[i+1] == 'rd') or (step[i] == 'rd' and step[i+1] == 'ld'):
            ans += 1
    print(ans)
