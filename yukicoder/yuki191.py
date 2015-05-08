n = int(input())
C = list(map(int, input().split()))
lim = sum(C) / 10
print(30*sum(1 for c in C if c <= lim))
