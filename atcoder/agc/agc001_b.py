drc = [(0, 1), (1, 1), (1, 0), (-1, 0), (-1, -1), (0, -1)]


def next_dir(d, w):
    return (d + 2) % 6 if d % 3 == (w + 2) % 3 else (d + 4) % 6

def main(N, X):
    start = (X, 0)
    now = (X, 1)
    wall = dict()
    for i in range(0, N):
        wall[N, i] = 0
        wall[i, i] = 1
        wall[i, 0] = 2
    d = 0
    ans = 1
    while True:
        assert(0 <= now[0] <= N and 0 <= now[1] <= N)
        if now in wall:
            if now == start:
                break
            d = next_dir(d, wall[now])
        else:
            wall[now] = d
        now = (now[0] + drc[d][0], now[1] + drc[d][1])
        ans += 1
    return ans

if __name__ == '__main__':
    #N, X = map(int, input().split())
    from math import gcd
    for N in range(2, 20):
        print(N, [main(N, X) for X in range(1, N)])
        print(N, [3 * (N - gcd(N, X)) for X in range(1, N)])
