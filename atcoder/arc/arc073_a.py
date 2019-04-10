N, T = map(int, input().split())
t = [int(x) for x in input().split()]
print(N * T - sum(max(0, T - (t[i+1] - t[i])) for i in range(N - 1)))
