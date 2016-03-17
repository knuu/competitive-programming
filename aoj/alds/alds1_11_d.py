V, E = map(int, input().split())
edge = [[] for _ in range(V)]
for _ in range(E):
    s, t = map(int, input().split())
    edge[s].append(t)
    edge[t].append(s)

group = [-1] * V
cnt = 0
for i in range(V):
    if group[i] == -1:
        group[i] = cnt
        stack = [i]
        while stack:
            v = stack.pop()
            for c in edge[v]:
                if group[c] == -1:
                    group[c] = cnt
                    stack.append(c)
        cnt += 1
for _ in range(int(input())):
    s, t = map(int, input().split())
    print('yes' if group[s] == group[t] else 'no')
