S = input()
origin = ['', 'K', 'I', 'H', '', 'B', '', 'R', '']
idx = [0, 4, 6, 8]
candidate = []
for state in range(1 << 4):
    tmp = origin[:]
    for i in range(4):
        if state >> i & 1:
            tmp[idx[i]] = 'A'
    candidate.append(''.join(tmp))
print("YES" if S in candidate else "NO")
