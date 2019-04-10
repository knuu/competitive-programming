from collections import Counter
S = input()
L = len(S)
ans = [''] * L
chara = []
chrstat = Counter(S).most_common
for (k, v) in reversed(Counter(S).most_common()):
    for _ in range(v):
        chara.append(k)
for i in range(0, L, 3):
    ans[i] = chara.pop()
for i in range(1, L, 3):
    ans[i] = chara.pop()
for i in range(2, L, 3):
    ans[i] = chara.pop()
ans = ''.join(ans)
print("YES" if all(ans[i] != ans[i + 1] for i in range(L - 1)) and \
      all(ans[i] != ans[i + 2] for i in range(L - 2)) else "NO")
