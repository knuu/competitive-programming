N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
counter = [0] * (N + 1)
for a in A:
    counter[a] += 1
before = after = 0
for i in range(1, N + 1):
    if counter[i] == 0:
        before = i
    elif counter[i] == 2:
        after = i
if before == after == 0:
    print("Correct")
else:
    print(after, before)
