N, K = map(int, input().split())
D = set(input().split())
while any(s in D for s in str(N)):
    N += 1
print(N)
