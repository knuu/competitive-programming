N = int(input())
A = [int(x) for x in input().split()]
ret = 0
for state in range(1 << N):
    flag = False
    ans = 1
    for i in range(N):
        if (state >> i & 1):
            if A[i] % 2 == 1:
                flag = True
            ans *= 2
        else:
            if A[i] % 2 == 0:
                flag = True
    if flag:
        ret += ans
print(ret)
