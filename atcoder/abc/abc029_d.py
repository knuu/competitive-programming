import heapq, bisect, math, collections, sys, fractions, copy, functools, operator, itertools, string

argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = input()
if int(N) < 10:
    print(1)
    exit(0)
L = len(N)
dp = [0] * L
dp[0] = 1
for i in range(L-2):
    dp[i+1] = pow(10, i+1) + 9 * sum(dp[:i+1])
for i in range(L):
    if i == 0:
        dp[L-1] += (int(N[i]) - 1) * sum(dp[:L-1-i])
    else:
        dp[L-1] += int(N[i]) * sum(dp[:L-1-i])
    if int(N[i]) > 1 or (i == L-1 and int(N[i]) >= 1):
        dp[L-1] += pow(10, L-i-1)
    elif int(N[i]) == 1:
        dp[L-1] += int(N[i+1:]) + 1
print(sum(dp))
