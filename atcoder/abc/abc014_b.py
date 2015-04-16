n, X = map(int, input().split())
A = list(map(int, input().split()))[::-1]
print(sum([a for a, b in zip(A, bin(X)[2:].zfill(n)) if int(b)]))
