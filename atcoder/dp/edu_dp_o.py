import sys
import ctypes


def popcount(N):
    if sys.platform.startswith('linux'):
        libc = ctypes.cdll.LoadLibrary('libc.so.6')
        return libc.__sched_cpucount(ctypes.sizeof(ctypes.c_long), (ctypes.c_long * 1)(N))
    elif sys.platform == 'darwin':
        libc = ctypes.cdll.LoadLibrary('libSystem.dylib')
        return libc.__popcountdi2(N)
    else:
        assert(False)


def main():
    N = int(input())
    mod = 10 ** 9 + 7
    A = [[int(x) for x in input().split()] for _ in range(N)]
    dp = [0] * (1 << N)
    dp[0] = 1
    for state in range(1 << N):
        dp[state] %= mod
        i = popcount(state)
        for j in range(N):
            if (state >> j & 1) == 0 and A[i][j]:
                dp[state | (1 << j)] += dp[state]
    print(dp[-1])



if __name__ == '__main__':
    main()
