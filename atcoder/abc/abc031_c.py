ans = -2500
N = int(input())
A = [int(x) for x in input().split()]
for i in range(N):
    score = []
    for j in range(N):
        if i == j:
            continue
        a, b = i, j
        if a > b:
            a, b = b, a
        subA = A[a:b+1]
        score.append((sum(subA[1::2]), -j, sum(subA[::2])))
    _, _, cand = max(score)
    ans = max(ans, cand)
print(ans)
