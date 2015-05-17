from math import ceil
X = int(input())
Y = int(input())
L = int(input())
turn = (X != 0 or Y < 0) + (Y < 0)
print(int(ceil(abs(X)/L)) + int(ceil(abs(Y)/L)) + turn)
