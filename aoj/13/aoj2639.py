a, b, c = map(int, input().split())
now = 0
used = [False] * 60
while True:
    sleep_start = now + a
    if now % 60 < sleep_start % 60:
        if now % 60 <= c <= sleep_start % 60:
            print(now // 60 * 60 + c)
            break
        now = sleep_start + b
    else:
        if now % 60 <= c < 60 or 0 < c <= sleep_start % 60:
            print(now // 60 * 60 + c)
            break
        now = sleep_start + b
    if now % 60 == 0:
        print(-1)
        break
