N = input()
ans = ''
dic = {'0': 'nil', '1': 'un', '2': 'bi', '3': 'tri', '4': 'quad', '5': 'pent', '6': 'hex', '7': 'sept', '8': 'oct', '9': 'enn'}
for i in range(3):
    if i > 0 and N[i-1] == '9' and N[i] == '0':
        ans = ans[:-1] + dic[N[i]]
    else:
        ans += dic[N[i]]
if ans[-1] == 'i':
    ans = ans[:-1] + 'ium'
else:
    ans += 'ium'
print(ans.title())
