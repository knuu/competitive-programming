M, N = map(int, input().split())
if M == 0:
    print(N+1)
elif M == 1:
    print(N+2)
elif M == 2:
    print(2*N+3)
elif M == 3:
    print(pow(2, N+3)-3)
