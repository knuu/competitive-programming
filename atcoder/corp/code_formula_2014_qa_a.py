A = int(input())
n = 1
while n ** 3 < A:
    n += 1
print('YES' if n ** 3 == A else 'NO')
