N = [int(x) for x in input()]
ans = sum(N)
for i in range(len(N)):
    if i == 0:
        N[0] -= 1
    else:
        N[i] = 9
print(max(ans, sum(N)))
