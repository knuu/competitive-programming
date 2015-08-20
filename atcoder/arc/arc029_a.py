N = int(input())
t = [int(input()) for _ in range(N)]
ans = 200
s = sum(t)
for i in t:
    ans = min(ans, max(s-i, i))
for i in range(N):
    for j in range(i+1, N):
        ans = min(ans, max(s-t[i]-t[j], t[i]+t[j]))
print(ans)
