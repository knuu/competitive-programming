N = int(input())
A, B, C = input(), input(), input()
ans = 0
for a, b, c in zip(A, B, C):
    L = len(set([a, b, c]))
    if L == 3:
        ans += 2
    elif L == 2:
        ans += 1
print(ans)
