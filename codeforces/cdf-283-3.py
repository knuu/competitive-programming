from copy import deepcopy

n, m = map(int, input().split())
words = [input() for _ in range(n)]

i = 1
ans = 0
while True:
    if i > len(words[0]): break
    for j in range(n-1):
        if words[j][:i] > words[j+1][:i]:
            ans += 1
            words = [x[:(i-1)]+x[i:] for x in words]
            i -= 1
            break
    i += 1

print(ans)
        
