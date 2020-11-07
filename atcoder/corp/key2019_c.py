N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

need = 0
small_num = 0
large = []
for a, b in zip(A, B):
    if a > b:
        large.append(a - b)
    elif a < b:
        need += b - a
        small_num += 1
large.sort()
for i, x in enumerate(reversed(large)):
    if need <= 0:
        print(i + small_num)
        quit()
    need -= x
if need <= 0:
    print(len(large) + small_num)
else:
    print(-1)
