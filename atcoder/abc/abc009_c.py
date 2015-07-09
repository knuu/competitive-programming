def check(ans, S, cnt):
    diff = 0
    for i in range(cnt):
        if ans[i] != S[i]:
            diff += 1
    r = rest[:]
    r.remove(ans[-1])
    for s in S[cnt:]:
        for i in r:
            if s == i:
                r.remove(i)
                break
        else:
            diff += 1
    return diff <= K    

N, K = map(int, input().split())
S = input()
lenS = len(S)
ans = ''
rest = list(S[:])
for i in range(N):
    for c in sorted(rest):
        if check(ans+c, S, i+1):
            rest.remove(c)
            ans += c
            break
print(ans)
