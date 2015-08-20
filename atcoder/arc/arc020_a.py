A, B = map(lambda x: abs(int(x)), input().split())
if A < B:
    print('Ant')
elif B < A:
    print('Bug')
else:
    print('Draw')
