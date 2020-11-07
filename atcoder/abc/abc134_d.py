N = int(input())

divisors = [[] for _ in range(N + 1)]

for i in range(1, N + 1):
    num = 2 * i
    while num <= N:
        divisors[num].append(i)
        num += i
ans = []
balls = [0] * (N + 1)
A = [int(x) for x in input().split()]
for i in reversed(range(1, N+1)):
    if balls[i] != A[i-1]:
        ans.append(i)
        balls[i] ^= 1
        for d in divisors[i]:
            balls[d] ^= 1

print(len(ans))
if ans:
    print(*ans)
