N = list(input())

flag = False
for i, n in enumerate(N):
    if flag:
        N[i] = '9'
    elif n == '4':
        flag = True
        N[i] = '3'
print(''.join(N))
