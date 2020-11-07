N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
ans = 0
for i in range(N):
    rest = B[i]
    use_i = min(rest, A[i])
    rest -= use_i
    ans += use_i
    use_ii = min(rest, A[i+1])
    ans += use_ii
    A[i+1] -= use_ii
print(ans)
