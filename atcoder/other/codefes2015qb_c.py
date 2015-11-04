N, M = map(int, input().split())
A = sorted(int(x) for x in input().split())
B = sorted(int(x) for x in input().split())
room = 0
for b in B:
    while room < N and A[room] < b:
        room += 1
    if room == N:
        print('NO')
        exit(0)
    room += 1
print('YES')
