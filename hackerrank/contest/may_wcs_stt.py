L, R = int(input()), int(input())
L -= 1
cnt = 0
ans_sum = 0
ans = []
while R > 0:
    if R - L < 10:
        ans_sum += R - L
        if R - L:
            ans.append((cnt, R - L))
        break
    c = 0
    if L % 10:
        c += 10 - L % 10
        L = L // 10 + 1
    else:
        L //= 10
    if R % 10:
        c += R % 10
    R //= 10
    if c:
        ans.append((cnt, c))
    cnt += 1
    ans_sum += c
print(ans_sum)
for cnt, c in ans:
    print(cnt, c)
