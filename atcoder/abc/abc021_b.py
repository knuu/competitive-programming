N = int(input())
town = [0] * N
a, b = map(lambda x: int(x)-1, input().split())
town[a] += 1
town[b] += 1
K = int(input())
p = list(map(lambda x: int(x)-1, input().split()))
for t in p:
    if town[t] > 0:
        print('NO')
        quit()
    else:
        town[t] += 1
print('YES')
