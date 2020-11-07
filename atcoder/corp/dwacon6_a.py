N = int(input())
titles, times = [], []
for _ in range(N):
    s, t = input().split()
    titles.append(s)
    times.append(int(t))
idx = titles.index(input())
ans = 0
for i in range(idx+1, N):
    ans += times[i]
print(ans)
