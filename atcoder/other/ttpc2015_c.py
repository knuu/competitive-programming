S = input()
rule = {0: 'Oo', 1: 'o', 2: 'O'}
while 'oookayama' in S:
    i = start = S.index('oookayama')
    i += 2
    end = start + len('oookayama')
    while start >= 0 and S[start] == 'o':
        start -= 1
    S = S[:start+1] + rule[(i - start) % 3] + 'kayama' + S[end:]
print(S)
