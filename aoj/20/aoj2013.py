def tosec(t):
    return int(t[:2])*60*60 + int(t[3:5])*60 + int(t[6:])

while True:
    n = int(input())
    if n == 0: break
    time = [0] * (60*60*24 + 1)

    for _ in range(n):
        s, f = input().split()
        time[tosec(s)] += 1
        time[tosec(f)] -= 1

    ans = time[0]
    for i in range(60*60*24):
        time[i+1] += time[i]
        ans = max(ans, time[i+1])

    print(ans)
