N = int(input())
happy = [tuple(map(int, input().split())) for _ in range(N)]
happy.sort(key=lambda x: x[0] + x[1])
result = [0, 0]
for i, x in enumerate(reversed(happy)):
    result[i % 2] += x[i % 2]
print(result[0] - result[1])
