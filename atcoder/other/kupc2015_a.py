def cut(s):
    cnt = 0
    while s:
        if s[:5] in ['tokyo', 'kyoto']:
            s = s[5:]
            cnt += 1
        else:
            s = s[1:]
    return cnt

T = int(input())
for i in range(T):
    print(cut(input()))
