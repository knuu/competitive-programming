S = input().split()
N = int(input())
print(*S)
for _ in range(N):
    next_S = input().split()
    for i in range(4):
        p = i // 2
        q = i % 2
        if S[p] == next_S[q]:
            next_S[q] = S[p^1]
            S = next_S
            print(*S)
            break
    else:
        assert(False)
