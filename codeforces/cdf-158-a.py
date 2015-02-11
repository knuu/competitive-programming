n, k = map(int, input().split())
scores = list(map(int, input().split()))
if 0 in scores:
    pos = scores.index(0)
    scores = scores[:pos]

ans = min(k, len(scores))
if k < len(scores):
    scores, fail = scores[:k], scores[k:]
    for p in fail:
        if p == scores[k-1]:
            ans += 1
        else:
            break
            
print(ans)
