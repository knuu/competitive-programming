a, b = int(input()), int(input())

s = 0
ans = [0]*(10**6+1)
for i in range(1, 10**6+1):
    s += i
    ans[i] = ans[i] + ans[i-1] + i*s
print((ans[b] - ans[a-1]) % (10**9 + 7))
