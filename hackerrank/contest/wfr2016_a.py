N = int(input())
ans = []
i = 0
while N >> i:
    if (N >> i) & 1:
        ans.append(i+1)
    i += 1
print(*ans[::-1])
