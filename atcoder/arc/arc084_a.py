from bisect import bisect_left
N = int(input())
A = sorted(int(x) for x in input().split())
B = sorted(int(x) for x in input().split())
C = sorted(int(x) for x in input().split())
cnt = [0] * (N + 1)
for i, b in enumerate(B):
    cnt[i + 1] = bisect_left(A, b)
    cnt[i + 1] += cnt[i]
print(sum(cnt[bisect_left(B, c)] for c in C))
