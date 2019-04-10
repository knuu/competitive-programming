N = int(input())
a = 1
l = []
while N:
    if all(str(a)[0] == s for s in str(a)):
        N -= 1
        l.append(str(a))
    a += 1
print(a-1)
print('[{}]'.format(','.join(l)))
