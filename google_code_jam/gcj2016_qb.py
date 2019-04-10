import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input


def compress_plus_count(S):
    return len(list(filter(lambda x: x, S.rstrip('+').split('-'))))

for i in range(int(input())):
    s = input()
    print("Case #{}: {}".format(i+1, compress_plus_count(s) * 2 + (s[0] == '-')))
