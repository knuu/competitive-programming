#!/bin/python3

t = int(input().strip())
for a0 in range(t):
    N = int(input().strip())
    a = [int(a_temp) for a_temp in input().strip().split(' ')]
    ans = 0
    for i in range(N-1):
        if not a[i] and not a[i+1]:
            ans += 1
            a[i+1] = 1
    print(ans)
