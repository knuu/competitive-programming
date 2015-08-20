N = int(input())
print('GO' if N % 4 == 0 else 'SEN')
"""
import sys
sys.setrecursionlimit(10**5)
def dfs(s):
    if s >= N:
        return False
    if memo[s] != -1:
        return memo[s]

    ret = False
    for i in range(3):
        if not dfs(s+i+1):
            ret = True
    memo[s] = ret
    return memo[s]


memo = [-1] * (10**4)
N = 100
dfs(0)
for i in range(100):
    print(i+1, memo[i])
"""
