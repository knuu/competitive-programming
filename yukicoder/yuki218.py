from math import ceil
a, b, c = int(input()), int(input()), int(input())
print('YES' if ceil(a/c)*3 <= 2*ceil(a/b) else 'NO')
