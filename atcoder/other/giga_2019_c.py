D = int(input())
INF = 10**10
ans = INF
money = 0

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

for a, b in zip(A, B):
    money += a
    if b <= money and b < ans:
        ans = b
print(ans if ans < INF else -1)
