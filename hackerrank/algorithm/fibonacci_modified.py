t1, t2, n = map(int, input().split())
for _ in range(n - 2):
    t1, t2 = t2, t1 + t2 ** 2
print(t2)
