range = xrange; input = raw_input
ans = (0, -10**5)
for i in range(int(input())):
    ans = max(ans, (int(input()), -i-1))
print(-ans[1])
