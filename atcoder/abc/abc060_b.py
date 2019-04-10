A, B, C = map(int, input().split())

M = set()
now = A % B

while now not in M:
    M.add(now)
    now = (now + A) % B

used = [False] * B
stack = list(M)
while stack:
    x = stack.pop()
    if used[x]:
        continue
    if x == C:
        print("YES")
        break
    used[x] = True
    for m in M:
        if not used[(x + m) % B]:
            stack.append((x + m) % B)
else:
    print("NO")
