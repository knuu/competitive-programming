m, n, pencils = map(int, input().split())

rest = 0
ans = pencils
while pencils:
    p, rest = divmod(pencils+rest, m)
    pencils = p * n
    ans += pencils
print(ans)
