N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

INF = 10**9
record_A = []
record_B = []

record_A.append((A[0], A[0]))

for i in range(1, N):
    if A[i] == A[i-1]:
        record_A.append((1, record_A[-1][1]))
    else:
        record_A.append((A[i], A[i]))

record_B.append((B[-1], B[-1]))

for i in reversed(range(N-1)):
    if B[i] == B[i+1]:
        record_B.append((1, record_B[-1][1]))
    else:
        record_B.append((B[i], B[i]))

ans = 1
mod = 10**9 + 7
for (lb_a, ub_a), (lb_b, ub_b) in zip(record_A, reversed(record_B)):
    lb, ub = max(lb_a, lb_b), min(ub_a, ub_b)
    if ub - lb < 0:
        print(0)
        break
    ans *= ub - lb + 1
    ans %= mod
else:
    print(ans)
