N = int(input())
A = [int(x) for x in input().split()]
if all(A[i] == 0 for i in range(N)):
    print("NO")
else:
    print("YES")
    ans = []
    nz_l, nz_r = 0, N-1
    while A[nz_l] == 0:
        nz_l += 1
    while A[nz_r] == 0:
        nz_r -= 1
    now = nz_l
    while now <= nz_r:
        total = 0
        for i in range(now, N):
            total += A[i]
            if A[i] != 0:
                ans.append([now, i])
                now = i + 1
                break
    ans[0][0] = 0
    ans[-1][1] = N-1
    print(len(ans))
    for l, r in ans:
        print(l+1, r+1)
