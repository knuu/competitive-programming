#range = xrange
#input = raw_input

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input().split()) for _ in range(N)]

N, L = read_list(int)
rabbits = [input().split() for _ in range(N)]
rabbits = [(-1, 'R'), (0, 'L')] + [(int(x), d) for x, d in rabbits] + [(L+1, 'R'), (L+2, 'L')]
rabbits = [dict([('pos', x), ('d', d)]) for x, d in rabbits]

group = 0
i = 0
flag = True
while i < N+4:
    if flag and rabbits[i]['d'] == 'R':
        rabbits[i]['group'] = group
    if not flag and rabbits[i]['d'] == 'R':
        group += 1
        flag = True
        rabbits[i]['group'] = group
    elif flag and rabbits[i]['d'] == 'L':
        flag = False
        rabbits[i]['group'] = group
    elif not flag and rabbits[i]['d'] == 'L':
        rabbits[i]['group'] = group
    i += 1

#print(*rabbits, sep='\n')
group += 1
groups = [[0, 0, 0, 0] for _ in range(group)]
for i in range(N+4):
    groups[rabbits[i]['group']][rabbits[i]['d'] != 'R'] += 1
    if i < N+3 and rabbits[i]['d'] == 'R' and rabbits[i+1]['d'] == 'L':
        groups[rabbits[i]['group']][2] = rabbits[i]['pos']
        groups[rabbits[i+1]['group']][3] = rabbits[i+1]['pos']

for i in range(group):
    if groups[i][0] > groups[i][1]:
        groups[i][2] = groups[i][3] - 1
    else:
        groups[i][3] = groups[i][2] + 1

ans = 0
for i in range(N+4):
    if rabbits[i]['d'] == 'R':
        ans += groups[rabbits[i]['group']][2] - rabbits[i]['pos']
    else:
        ans += rabbits[i]['pos'] - groups[rabbits[i]['group']][3]

for i in range(group):
    rg, lg = groups[i][0], groups[i][1]
    ans -= (rg-1) * rg // 2 + (lg-1) * lg // 2
print(ans)
