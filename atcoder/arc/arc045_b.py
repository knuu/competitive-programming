N, M = map(int, input().split())
rooms = [0] * (N+1)
students = [[int(x)-1 for x in input().split()] for _ in range(M)]
for s, t in students:
    rooms[s] += 1
    rooms[t+1] -= 1

one = [0] * (N+1)
for i in range(N):
    rooms[i+1] += rooms[i]
    one[i+1] += rooms[i] == 1
    one[i+1] += one[i]

ans = []
for i, (s, t) in enumerate(students):
    if one[t+1] - one[s] == 0:
        ans.append(i+1)
print(len(ans))
if ans:
    print(*ans, sep='\n')
