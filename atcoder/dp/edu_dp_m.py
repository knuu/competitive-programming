import sys
sys.setrecursionlimit(2 * 10**5)
mod = 10 ** 9 + 7


def main():
    N, K = map(int, input().split())
    A = [int(x) for x in input().split()]
    dp = [0] * (K + 1)
    dp[0] = 1
    for i in range(N):
        acc = [0]
        for x in dp:
            acc.append((acc[-1] + x) % mod)
        dp_ = []
        for j in range(K+1):
            dp_.append((acc[j+1] - acc[max(0, j-A[i])] + mod) % mod)
        dp = dp_
    print(dp[K])


if __name__ == '__main__':
    main()
