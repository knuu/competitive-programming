A = int(input())
if A == 0:
    print("Yes")
    quit()
for s in input():
    A += 1 if s == '+' else -1
    if A == 0:
        print("Yes")
        quit()
print("No")
