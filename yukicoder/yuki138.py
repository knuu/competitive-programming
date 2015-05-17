a1, b1, c1 = map(int, input().split('.'))
a2, b2, c2 = map(int, input().split('.'))
print('YES' if  a1 > a2 or (a1 == a2 and b1 > b2) or (a1 == a2 and b1 == b2 and c1 >= c2) else 'NO') 
