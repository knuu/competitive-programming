n = input()
ans1 = max([int(x) for x in n])
ans2 = ['' for _ in range(ans1)]
for i in n:
    cnt = int(i)
    for j in range(ans1):
        if cnt > 0:
            ans2[j] += '1'
            cnt -= 1
        else:
            ans2[j] += '0'
print(ans1)
print(' '.join([str(int(x)) for x in ans2]))

