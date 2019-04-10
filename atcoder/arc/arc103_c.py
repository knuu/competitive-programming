S = [int(x) for x in input()]
N = len(S)
if S[0] == 0 or S[-1] == 1 or any(S[i] != S[-i - 2] for i in range(N - 1)):
    print(-1)
    quit()

edge = [(1, 2)]
root, now = 2, 3
for i in range(1, N // 2 + 1):
    edge.append((root, now))
    if S[i] == 1:
        root = now
    now += 1
while now <= N:
    edge.append((root, now))
    now += 1
for s, t in edge:
    print(s, t)
