A, K = map(int, input().split())

ans = A
for i in range(len(str(A))):
    for p in range(10):
        for q in range(10):
            s = str(A)[:i] + str(p) + str(q) * (len(str(A))-i-1)
            if (len(set(str(int(s)))) <= K):
                ans = min(ans, abs(A-int(s)))
print(ans)
