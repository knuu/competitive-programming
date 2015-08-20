S = input().lower()
for s in 'ict':
    if s in S:
        S = S[S.index(s):]
    else:
        print('NO')
        break
else:
    print('YES')
