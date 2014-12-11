a,b,c = map(int, input().split())
if a + b != c and a - b != c:
    print('!')
elif b == 0:
    print('?')
elif a + b == c:
    print('+')
elif a - b == c:
    print('-')

