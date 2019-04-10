a = [int(x) for x in input().split()]
if all(x in a for x in [1, 9, 7, 4]):
    print("YES")
else:
    print("NO")
