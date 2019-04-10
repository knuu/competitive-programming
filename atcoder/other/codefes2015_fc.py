N, S = int(input()), input()
neta, shari = 0, 0
ans = 0
i = 0
while i < 2 * N - 1:
    now = S[i:i+2]
    if now in ['01', '10']:
        i += 2
    elif now == '11':
        if neta == 0:
            ans += 1
            shari += 1
        else:
            neta -= 1
        i += 1
    elif now == '00':
        if shari == 0:
            ans += 1
            neta += 1
        else:
            shari -= 1
        i += 1
# assert(neta == shari == 0)
print(ans)
