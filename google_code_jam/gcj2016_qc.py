import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input


_ = input()
N, J = map(int, input().split())
print("Case #1:")
a = (1 << N-1) + 1
cnt = 0
for b in range(1 << N-2):
    if cnt == J:
        break
    bit = a + (b << 1)
    out = [''.join('1' if bit >> i & 1 else '0' for i in range(N))[::-1]]
    for base in range(2, 11):
        base_num = sum((bit >> i & 1) * pow(base, i) for i in range(N))
        for d in [2, 3, 5, 7, 11]:
            if base_num % d == 0:
                out.append(d)
                break
        else:
            break
    else:
        assert(len(out) == 10)
        print(' '.join(map(str, out)))
        cnt += 1
assert(cnt == J)
