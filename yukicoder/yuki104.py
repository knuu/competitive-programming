ans = 1
for s in input():
    if s == 'L':
        ans = ans * 2
    elif s == 'R':
        ans = ans * 2 + 1
print(ans)
