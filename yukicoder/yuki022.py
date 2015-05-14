N, K = map(int, input().split())
S = input()
par = [0] * len(S)
par[0] = 1
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        par[i+1] = par[i]
    elif S[i] == '(':
        par[i+1] = par[i] + 1
    elif S[i] == ')':
        par[i+1] = par[i] - 1
if S[K-1] == '(':
    i = K
    while True:
        if par[K-1] == par[i]:
            print(i+1)
            break
        i += 1
else:
    i = K-2
    while True:
        if par[K-1] == par[i]:
            print(i+1)
            break
        i -= 1
