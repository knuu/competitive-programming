N = int(input())
ans = 0
for i in range(N):
    sh, sm, eh, em = map(int, input().replace(':', ' ').split())
    delta = (eh*60 + em) - (sh*60 + sm)
    if delta < 0: delta += 24*60
    ans += delta
print(ans)
