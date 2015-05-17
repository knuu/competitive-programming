F0, F1, N = map(int, input().split())
if N % 3 == 0:
    print(F0)
elif N % 3 == 1:
    print(F1)
else:
    print(F0^F1)
