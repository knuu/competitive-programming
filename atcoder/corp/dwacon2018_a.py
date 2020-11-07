N = int(input())
A = [int(x) for x in input().split()]
S = sum(A)
min_res = S * N
ans = -1
for i, a in enumerate(A):
    if abs(N * a - S) < min_res:
        ans = i
        min_res = abs(N * a - S)
print(ans)
