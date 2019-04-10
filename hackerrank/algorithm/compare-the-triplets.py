A, B = [int(x) for x in input().split()], [int(x) for x in input().split()]
print(sum(a > b for a, b in zip(A, B)), sum(a < b for a, b in zip(A, B)))
