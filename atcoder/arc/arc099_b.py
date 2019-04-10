def S(n):
    return sum(int(x) for x in str(n))
rest = K = int(input())

ans = list(range(1, 10))

rest -= 9
suffix = 10
i = 0
while rest > 0:
    num = int(str(suffix) + '9' * i)
    if suffix % 10 == 0:
        next_suffix = suffix + 9
        next_num = int(str(next_suffix) + '9' * i)
        if num / S(num) > next_num / S(next_num):
            i += 1
            suffix //= 10
        num = int(str(suffix) + '9' * i)
    ans.append(num)
    rest -= 1
    suffix += 1

for i in range(K):
    print(ans[i])
