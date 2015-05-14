N = int(input())
numSet = {i for i in range(10)}
for _ in range(N):
    q = input().split()
    num = set(list(map(int, q[:4])))
    R = q[4]
    if R == 'YES':
        numSet &= num
    if R == 'NO':
        numSet -= num
print(numSet.pop())
