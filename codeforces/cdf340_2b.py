N = int(input())
choco = [int(x) for x in input().split()]
if all(c == 0 for c in choco):
    print(0)
    exit(0)
ans = 1
i = 0
while choco[i] == 0:
    i += 1

while True:
    assert(choco[i] == 1)
    j = i+1
    while j < N and choco[j] == 0:
        j += 1
    if j == N:
        break
    else:
        ans *= j - i
    i = j
print(ans)
