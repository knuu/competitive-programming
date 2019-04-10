N, M = map(int, input().split())
S = input()
actors = list()
for _ in range(M):
    _, c = map(int, input().split())
    dic = set(list(input()))
    actors.append((c, dic))
actors.sort()

ans = 0
for s in S:
    for c, d in actors:
        if s in d:
            ans += c
            break
    else:
        print(-1)
        exit(0)
print(ans)
