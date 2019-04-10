x = int(input())
if x % 11 == 0:
    print(x // 11 * 2)
else:
    cnt = x // 11 * 2
    x -= cnt // 2 * 11
    assert(x < 11)
    if x <= 6:
        print(cnt + 1)
    else:
        print(cnt + 2)
