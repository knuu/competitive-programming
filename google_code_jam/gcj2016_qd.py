import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input

for i in range(int(input())):
    S, C, K = map(int, input().split())
    print('Case #{}: {}'.format(i+1, ' '.join(map(str, range(1, S+1)))))
