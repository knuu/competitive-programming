import itertools
M, K = map(int, input().split())

if K >= (1 << M):
    print(-1)
    quit()

if M == 0:
    print(0, 0)
    quit()

if M == 1:
    if K == 0:
        print(0, 0, 1, 1)
    else:
        print(-1)
    quit()


A = [i for i in range(1 << M) if i != K]
print(*(A + [K] + A[::-1] + [K]))
