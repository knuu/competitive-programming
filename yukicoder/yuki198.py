B = int(input())
N = int(input())
C = [int(input()) for _ in range(N)]
C.sort()
sumC = B + sum(C)
t = min(sumC//N, C[N//2])
ans = sum(abs(x - t) for x in C)
print(ans)
