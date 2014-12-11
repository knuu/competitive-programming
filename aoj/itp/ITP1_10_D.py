n = int(input())
x, y = [list(map(int, input().split())) for _ in range(2)]
print(sum([abs(x[i] - y[i]) for i in range(n)]))
print(pow(sum([(x[i] - y[i]) ** 2 for i in range(n)]), 1/2))
print(pow(sum([abs(x[i] - y[i]) ** 3 for i in range(n)]), 1/3))
print(max([abs(x[i] - y[i]) for i in range(n)]))

