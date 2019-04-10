def count_div(start, end, div):
    # [start, end)
    return (end - 1) // div - (start - 1) // div


def calc_start(mid):
    cnt, i = 0, 1
    while 10 ** i < mid:
        d, p = 10 ** i, 10 ** (i - 1)
        fif, three, five = count_div(p, d, 15), count_div(p, d, 3), count_div(p, d, 5)
        cnt += i * (d - p) + (three + five) * 4 - (three + five - fif) * i
        i += 1
    d = 10 ** (i - 1)
    fif, three, five = count_div(d, mid, 15), count_div(d, mid, 3), count_div(d, mid, 5)
    cnt += i * (mid - d) + (three + five) * 4 - (three + five - fif) * i
    return cnt


N = int(input()) - 1
left, right = 1, 10 ** 18
while left + 1 < right:
    mid = (left + right) // 2
    start = calc_start(mid)
    if start <= N:
        left = mid
    else:
        right = mid
ans = ''
for i in range(left, left + 9):
    tmp = ''
    if i % 3 == 0:
        tmp += "Fizz"
    if i % 5 == 0:
        tmp += "Buzz"
    if not tmp:
        tmp = str(i)
    ans += tmp
start = calc_start(left)
print(ans[N - start:N - start + 20])
