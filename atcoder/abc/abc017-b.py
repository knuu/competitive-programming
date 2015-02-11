x = input()
while x:
    if x[-1] in 'oku':
        x = x[:-1]
    elif len(x) >= 2 and x[-2:] == 'ch':
        x = x[:-2]
    else:
        break

print('YES' if x == '' else 'NO')
