S = input()
T = input()
for s, t in zip(S, T):
    if (s == t) or (s == '@' and t in 'atcoder') or (t == '@' and s in 'atcoder'):
        continue
    else:
        print('You will lose')
        exit(0)
print('You can win')
