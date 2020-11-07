N, M = map(int, input().split())
lines = [None] * N
stack = [0]
edges = [[] for _ in range(N)]
for _ in range(M):
    l, r, d = map(int, input().split())
    edges[l-1].append((r-1, d))
    edges[r-1].append((l-1, -d))

for i in range(N):
    if lines[i] is not None:
        continue
    lines[i] = 0
    stack = [i]
    while stack:
        v = stack.pop()
        for u, d in edges[v]:
            if lines[u] is None:
                lines[u] = lines[v] + d
                stack.append(u)
            elif lines[v] + d != lines[u]:
                print("No")
                quit()

print("Yes")
