def main() -> None:
    N = int(input())
    P = [int(input()) for _ in range(N)]
    print("first" if any(x % 2 == 1 for x in P) else "second")


if __name__ == '__main__':
    main()
