N = int(input())
A = [int(input()) for _ in range(N)]
dic = {}
ans = 0
for a in A:
    if dic.get(a, 0) > 0:
        ans += 1
    else:
        dic[a] = 1
print(ans)
