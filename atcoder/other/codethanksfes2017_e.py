N = int(input())
ans = [0] * N
for i in range(0, N, 5):
    q = [0] * N
    for j in range(i, min(N, i + 5)):
        q[j] = 10 ** (j - i)
    print('? {}'.format(' '.join(map(str, q))), flush=True)
    S = str(int(input().strip()) - sum(q) * 7)[::-1]
    for j in range(i, min(N, i + 5)):
        ans[j] = (int(S[j - i]) % 2) ^ 1
print('! {}'.format(' '.join(map(str, ans))), flush=True)
