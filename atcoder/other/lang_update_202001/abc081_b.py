def main() -> None:
    N = int(input())
    ans = 10 ** 9
    for x in map(int, input().split()):
        cnt = 0
        while x % 2 == 0:
            x >>= 1
            cnt += 1
        ans = min(ans, cnt)
    print(ans)


if __name__ == '__main__':
    main()
