def main() -> None:
    N = int(input())
    t, x, y = 0, 0, 0
    for _ in range(N):
        nt, nx, ny = map(int, input().split())
        dist, diff = abs(x - nx) + abs(y - ny), nt - t
        if dist > diff or dist % 2 != diff % 2:
            print("No")
            return
    print("Yes")


if __name__ == '__main__':
    main()
