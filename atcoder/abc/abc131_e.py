N, K = map(int, input().split())
if (N - 1) * (N - 2) // 2 < K:
    print(-1)
    quit()


ans = []
for i in range(1, N):
    ans.append((1, i+1))

now_K = (N - 1) * (N - 2) // 2


def f():
    global now_K
    for i in range(1, N):
        for j in range(i+1, N):
            if now_K == K:
                break
            ans.append((i+1, j+1))
            now_K -= 1
f()
print(len(ans))
for a, b in ans:
    print(a, b)
