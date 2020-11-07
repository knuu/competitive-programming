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

S = input()
N = len(S)
ans = N
for state in range(1 << N):
    cand = 0
    used = [False] * N
    for i in range(N):
        if state >> i & 1:
            for j in range(N):
                if S[j] == "o":
                    used[(i + j) % N] = True
    if sum(used) == N:
        ans = min(ans, popcount(state))

print(ans)
