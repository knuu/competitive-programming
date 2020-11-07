N, K = map(int, input().split())
A = [int(x) for x in input().split()]
acc = [0]
for a in A:
    acc.append(acc[-1] + a)
B = []
for i in range(N):
    for j in range(i + 1, N + 1):
        B.append(acc[j] - acc[i])
B.sort()
count_dict = dict()
for b in B:
    count_dict[b] = count_dict.get(b, 0) + 1
ans = 0
for i in reversed(range(40)):
    bit = 1 << i
    if sum(v for k, v in count_dict.items() if ((ans + bit) & k) == ans + bit) >= K:
        ans += bit
print(ans)
