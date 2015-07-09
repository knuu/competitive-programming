n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()

cnt = 0
s = 0
for ai in a:
    if s < ai:
        cnt += 1
        s += ai

print(cnt)
