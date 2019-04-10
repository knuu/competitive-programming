N = int(input())
A = [int(x) for x in input().split()]
if sum(A) % (N * (N + 1) // 2) != 0:
    print("NO")
    quit()
res = sum(A) // (N * (N + 1) // 2)
cnt = 0
for i in range(N):
    d = A[i] - A[(i+1)%N]
    if d + res < 0 or (d + res) % N != 0:
        print("NO")
        quit()
    cnt += (d + res) // N
print("YES" if cnt == res else "NO")
