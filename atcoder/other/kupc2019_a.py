N, X = map(int, input().split())
A = [int(x) for x in input().split()]
max_A = max(A)


print(sum(a + X >= max_A for a in A))
