a,b,c,d = map(int, input().split())
m = max(3*a/10, a - a*c/250)
v = max(3*b/10, b - b*d/250)
if m > v:
    print('Misha')
elif m < v:
    print('Vasya')
else:
    print('Tie')
