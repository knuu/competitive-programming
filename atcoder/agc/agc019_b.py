A = input()
cnt = dict()
for a in A:
    cnt[a] = cnt.get(a, 0) + 1
ans = len(A) * (len(A) - 1) // 2 + 1

for v in cnt.values():
    ans -= v * (v - 1) // 2
print(ans)
