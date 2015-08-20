left, right = 1, 10**9+1
while right - left > 1:
    mid = (left + right) // 2
    print('? {}'.format(mid), flush=True)
    if int(input()):
        left = mid
    else:
        right = mid
print('! {}'.format(left), flush=True)
