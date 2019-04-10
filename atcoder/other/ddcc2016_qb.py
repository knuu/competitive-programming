from math import sqrt
R, N, M = map(int, input().split())
x = []
for i in range((N-1)//2):
    x.append(R-2*R/N*(i+1))
x_rev = x[::-1]
if N % 2 == 0:
    x.append(0.)
x.extend(x_rev)
assert(len(x) == N-1)

cut1 = []
for i in range(N+M-1):
    if i < N - 1:
        cut1.append(sqrt(R**2 - x[i]**2) * 2)
    else:
        cut1.append(0)
cut2 = []
for i in range(N+M-1):
    if i >= M:
        cut2.append(sqrt(R**2 - x[i-M]**2) * 2)
    else:
        cut2.append(0)
assert(len(cut1) == len(cut2))
assert(sum(a == 0.0 for a in cut1) == M)
assert(sum(a == 0.0 for a in cut2) == M)
print('{:.20}'.format(sum(max(a, b) for a, b in zip(cut1, cut2))))
