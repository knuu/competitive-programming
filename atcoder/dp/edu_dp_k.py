import sys
sys.setrecursionlimit(2*10**5)

def rec(i, A, memo):
    if memo[i] != -1:
        return memo[i]

    for a in A:
        if i - a >= 0 and not rec(i - a, A, memo):
            memo[i] = True
            return True
    memo[i] = False
    return False


def main():
    N, K = map(int, input().split())
    A = [int(x) for x in input().split()]
    memo = [-1] * (K + 1)
    print("First" if rec(K, A, memo) else "Second")


if __name__ == '__main__':
    main()
