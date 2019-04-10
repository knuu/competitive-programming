N, M, K = map(int, input().split())
A = [int(x) for x in input().split()][::-1]
B = [int(x) for x in input().split()][::-1]
while len(A) < len(B):
    A.append(0)
while len(A) > len(B):
    B.append(0)
A, B = A[::-1], B[::-1]
if A < B:
    print("X")
elif A > B:
    print("Y")
else:
    print("Same")
