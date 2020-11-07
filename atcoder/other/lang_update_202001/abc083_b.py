def main() -> None:
    N, A, B = map(int, input().split())
    ans = 0
    for i in range(1, N+1):
        ans += i * (A <= sum(map(int, str(i))) <= B)
    print(ans)


if __name__ == '__main__':
    main()
