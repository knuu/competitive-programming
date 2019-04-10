N = int(input())
N %= 6
x = int(input())
b = [0, 1, 2]
for i in range(N):
    if i % 2 == 0:
        b[0], b[1] = b[1], b[0]
    else:
        b[1], b[2] = b[2], b[1]
print(b[x])
