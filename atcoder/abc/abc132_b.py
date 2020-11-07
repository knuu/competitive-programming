N = int(input())
P = [int(x) for x in input().split()]
ans = 0
for i in range(1, N-1):
    if P[i-1] < P[i] < P[i+1] or P[i+1] < P[i] < P[i-1]:
        ans += 1
print(ans)
