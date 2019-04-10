def count_bit_sum(N):
    bit = [0] * max_bitlen
    if N <= 0:
        return bit[:]
    for i in range(N.bit_length() - 1):
        bit[i] = 1 << (N.bit_length() - 2)
    bit[N.bit_length()-1] = N - (1 << (N.bit_length() - 1)) + 1
    return [bit[i] + b for i, b in enumerate(count_bit_sum(N - (1 << (N.bit_length() - 1))))]
max_bitlen = int(1<<31).bit_length()

L, R = map(int, input().split())
ans = [(r - l) * 2 > (R - L + 1) for l, r in zip(count_bit_sum(L-1), count_bit_sum(R))]
print(sum(x * (1 << i) for i, x in enumerate(ans)))
