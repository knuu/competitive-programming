N, M, A, B = map(int, input().split())
C = [int(input()) for _ in range(M)]
for i, c in enumerate(C):
    if N <= A:
        N += B
    N -= c
    if N < 0:
        print(i+1)
        break
else:
    print('complete')
