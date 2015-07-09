n, t = map(int, input().split())
a = [int(input()) for _ in range(n)]
o = [0] * t
for i in a:
    for j in range(i-1,t,i):
        o[j] += 1
print(max(o))
