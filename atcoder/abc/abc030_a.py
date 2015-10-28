A, B, C, D = map(int, input().split())
if A * D == B * C:
    print('DRAW')
elif B * C > A * D:
    print('TAKAHASHI')
else:
    print('AOKI')
