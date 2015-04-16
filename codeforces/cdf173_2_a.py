n = int(input())
X = 0
for i in range(n):
    if "++" in input():
        X += 1
    else:
        X -= 1
print(X)
