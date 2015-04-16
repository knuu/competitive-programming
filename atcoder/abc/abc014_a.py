a, b = int(input()), int(input())
if a % b == 0:
    print(0)
else:
    print(b - a % b)
