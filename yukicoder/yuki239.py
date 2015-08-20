N = int(input())
A = [input().split() for _ in range(N)]
renge = []
for i in range(N):
    for j in range(N):
        if i != j and A[j][i] != 'nyanpass':
            break
    else:
        renge.append(i)
if len(renge) == 1:
    print(renge[0] + 1)
else:
    print(-1)
