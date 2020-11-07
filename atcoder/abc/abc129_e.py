import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
L = input()
N = len(L)
MOD = 10 ** 9 + 7
bits = [1, 2]
acc = [1, 3]
for _ in range(N):
    nex = bits[-1] * 3 % MOD
    bits.append(nex)
    acc.append((acc[-1] + nex) % MOD)
ans = acc[N-1]
cnt = 1
for i, b in enumerate(L):
    if i == 0:
        continue
    now = N-i-1
    if b == '1':
        ans += acc[now] * pow(2, cnt, MOD) % MOD
        cnt += 1
    ans %= MOD
ans += pow(2, cnt, MOD)
ans %= MOD
print(ans)
