N = int(input())
A = [(int(input()), i) for i in range(N)]
A.sort()
x1, i1 = A[-1]
x2, i2 = A[-2]

for i in range(N):
    if i == i1:
        print(x2)
    else:
        print(x1)
