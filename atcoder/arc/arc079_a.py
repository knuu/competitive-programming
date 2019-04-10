N, M = map(int, input().split())
edges = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)
for e in edges[0]:
    if any(c == N - 1 for c in edges[e]):
        print("POSSIBLE")
        quit()
print("IMPOSSIBLE")
