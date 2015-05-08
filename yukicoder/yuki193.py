
def elmLead0(s):
    s = s.replace('+', ' + ')
    s = s.replace('-', ' - ')
    ret = []
    for x in s.split():
        if x in '+-':
            ret.append(x)
        else:
            ret.append(str(int(x)))
    return ''.join(ret)

s = input()
ans = -(10**9)
for i in range(len(s)):
    t = s[i:] + s[:i]
    if t[0] not in '+-' and t[-1] not in '+-':
        ans = max(ans, eval(elmLead0(t)))

print(ans)

