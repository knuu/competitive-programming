input = raw_input; range = xrange
for _ in range(int(input())):
    ans = 0
    l, r = map(int, input().split())
    for i in range(l, r+1):
        if str(i) == str(i)[::-1]:
            ans += i
    print(ans)
