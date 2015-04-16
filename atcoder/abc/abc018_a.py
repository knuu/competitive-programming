A = int(input())
B = int(input())
C = int(input())

l = sorted([A, B, C])[::-1]
print(l.index(A)+1)
print(l.index(B)+1)
print(l.index(C)+1)
