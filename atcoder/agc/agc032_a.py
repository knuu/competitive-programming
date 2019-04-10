N = int(input())
B = [int(x) - 1 for x in input().split()]
ans = []
while B:
    popped = -1
    for i in reversed(range(len(B))):
        x = B[i]
        if B[i] == i:
            ans.append(i + 1)
            popped = B.pop(i)
            break
    if popped == -1:
        print(-1)
        quit()
print(*ans[::-1], sep="\n")
