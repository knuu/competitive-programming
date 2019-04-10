A, B = map(int, input().split())
if A + B > A * B:
    print('S')
elif A + B == A * B:
    print('E')
else:
    print('P')
