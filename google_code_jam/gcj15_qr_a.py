N = int(input())
for i in range(N):
    shymax, audience = input().split()
    shymax = int(shymax)
    audience = [int(x) for x in audience]
    ans = 0
    stand = 0
    for aud in audience:
        stand += aud - 1
        if stand < 0:
            ans += 1
            stand = 0
    print("Case #{}: {}".format(i+1, ans))
