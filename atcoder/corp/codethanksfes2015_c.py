N = int(input())
H = [int(x) for x in input().split()]
X = int(input())
if X < H[0]:
    print(1)
else:
    for i in range(N-1):
        if H[i] < X < H[i+1]:
            print(i+2)
            break
    else:
        print(N+1)
