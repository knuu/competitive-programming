A, B = map(int, input().split())
if A == B:
    print(0)
elif (A + B) % 2 == 0:
    print((A + B) // 2)
else:
    print("IMPOSSIBLE")
