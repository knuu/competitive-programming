N = int(input())
ans = ''
for _ in range(N):
    p, q, r = input().split()
    if p == 'BEGINNING':
        ans += r[0]
    elif p == 'MIDDLE':
        ans += r[len(r)//2]
    else:
        ans += r[-1]
print(ans)
