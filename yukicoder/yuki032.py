L = int(input())
M = int(input())
N = int(input())
ans = 0

ans += N % 25
M += N // 25

ans += M % 4
L += M // 4

ans += L % 10
print(ans)
