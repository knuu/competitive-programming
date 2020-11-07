N = int(input())

notes = []
for _ in range(N):
    note = []
    for _ in range(int(input())):
        x, y = map(int, input().split())
        note.append((x-1, y))
    notes.append(note)

ans = 0
for state in range(1 << N):
    flag = True
    for i in range(N):
        if state >> i & 1:
            for x, y in notes[i]:
                flag &= (y == 1 and state >> x & 1) or (y == 0 and (state >> x & 1) == 0)

    if flag:
        ans = max(ans, sum(state >> i & 1 for i in range(N)))
print(ans)
