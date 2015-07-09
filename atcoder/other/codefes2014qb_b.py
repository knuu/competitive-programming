N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
f = 0
for i, a in enumerate(A):
    f += a
    if f >= K:
        print(i+1)
        break
    
