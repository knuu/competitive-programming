def solve(n, m):
    return min(abs(n-m), abs(10+n-m), abs(10+m-n))

n = int(input())
S = input()
T = input()
ans = 0
for s, t in zip(S, T):
    ans += solve(int(s), int(t))
print(ans)
