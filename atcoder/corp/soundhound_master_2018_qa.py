A, B = map(int, input().split())
if A + B == 15:
    print('+')
elif A * B == 15:
    print('*')
else:
    print("x")
