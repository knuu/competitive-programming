P, A, B = map(int, input().split())
if P >= A+B:
    print(P)
elif B > P:
    print(-1)
else:
    print(A+B)
