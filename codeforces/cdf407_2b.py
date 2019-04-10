b, q, l, m = map(int, input().split())
A = set(map(int, input().split()))

if b == 0:
    print(0 if 0 in A else "inf")
elif q == 0:
    if 0 in A:
        print(1 if b not in A and abs(b) <= l else 0)
    else:
        print("inf")
elif q == 1:
    print(0 if b in A or abs(b) > l else 'inf')
elif q == -1:
    print(0 if (-b in A and b in A) or abs(b) > l else 'inf')
else:
    ans = 0
    while abs(b) <= l:
        ans += b not in A
        b *= q
    print(ans)
