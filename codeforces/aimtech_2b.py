N = int(input())
ans = 0
used = set()
for c in sorted([int(x) for x in input().split()], reverse=True):
    while c > 0 and c in used:
        c -= 1
    ans += c
    used.add(c)
print(ans)
