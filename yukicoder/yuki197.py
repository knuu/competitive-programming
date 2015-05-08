Sb = input()
N = int(input())
Sa = input()
if Sb.count('o') != Sa.count('o'):
    print('SUCCESS')
    exit(0)

if Sb.count('o') == 3 or Sb.count('o') == 0:
    print('FAILURE')
    exit(0)
if N == 0:
    print('FAILURE' if Sb == Sa else 'SUCCESS')
    exit(0)

swap = {'o': 'x', 'x': 'o'}
if Sb.count('o') == 2:
    Sb = ''.join([swap[x] for x in Sb])
    Sa = ''.join([swap[x] for x in Sa])

if Sb == 'oxx' or Sb == 'xxo':
    if N == 1 and Sa == Sb[::-1]:
        print('SUCCESS')
    else:
        print('FAILURE')
elif Sb == 'xox':
    if N == 1 and Sa == 'xox':
        print('SUCCESS')
    else:
        print('FAILURE')
