E = [int(x) for x in input().split()]
B = int(input())
L = [int(x) for x in input().split()]

cnt = sum(True for l in L if l in E)
if cnt == 6:
    print(1)
elif cnt == 5 and all(l in E+[B] for l in L):
    print(2)
elif cnt == 5:
    print(3)
elif cnt == 4:
    print(4)
elif cnt == 3:
    print(5)
else:
    print(0)
