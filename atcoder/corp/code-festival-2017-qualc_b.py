def main() -> None:
    N = int(input())
    ans = 3 ** N
    odd = 1
    for a in map(int, input().split()):
        if a % 2 == 0:
            odd *= 2
    print(ans - odd)


if __name__ == '__main__':
    main()
