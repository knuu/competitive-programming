N = int(input())
ans = 0
for i in range(N):
    row = [int(x) for x in input().split()]
    ans += row[i] - row[N-i-1]
print(abs(ans))
