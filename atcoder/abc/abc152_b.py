a, b = input().split()
print(a * int(b) if a * int(b) < b * int(a) else b * int(a))
