import sys
if int(sys.version[0]) == 2:
    range, input = xrange, raw_input
T = int(input())
for i in range(T):
    N = int(input())
    if N == 0:
        print("Case #{}: INSOMNIA".format(i+1))
    else:
        k = 1
        digits = set()
        while True:
            for s in str(k * N):
                digits.add(s)
            if len(digits) == 10:
                print("Case #{}: {}".format(i+1, k*N))
                break
            else:
                k += 1
