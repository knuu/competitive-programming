N, X = map(int, input().split())
A = sorted(map(int, input().split()))
ans = 0
for a in A:
    if X < a:
        break
    X -= a
    ans += 1
if ans == N and X != 0:
    ans -= 1
print(ans)
