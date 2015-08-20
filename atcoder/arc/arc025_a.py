D = [int(x) for x in input().split()]
J = [int(x) for x in input().split()]
print(sum(max(d, j) for d, j in zip(D, J)))
