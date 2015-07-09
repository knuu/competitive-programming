n = int(input())
w = [list(map(lambda x: int(x)-1, input().split())) for _ in range(n)]
syussya = [0] * (n*2)
for s, _ in w:
    syussya[s] += 1
for i in range(1, n*2):
    syussya[i] += syussya[i-1]
for s, t in w:
    print(syussya[t] - syussya[s])
