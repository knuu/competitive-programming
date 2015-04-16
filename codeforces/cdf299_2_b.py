n = input()
ans = 0
len_n = len(n)
if len_n == 1:
    if n == '4':
        ans = 1
    else:
        ans = 2
else:
    ans += sum([2 ** n for n in range(1, len_n)])
    for i in range(len_n):
        if n[i] == '7':
            ans += 2 ** (len_n-i-1)
    ans += 1
print(ans)
