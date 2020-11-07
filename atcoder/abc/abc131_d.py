N = int(input())
jobs = []
for _ in range(N):
    A, B = map(int, input().split())
    jobs.append((B, A))
jobs.sort(reverse=True)
now = 10 ** 9
for b, a in jobs:
    if now < b:
        now -= a
    else:
        now = b - a
print("Yes" if now >= 0 else "No")
