def main() -> None:
    A, B, C, X = [int(input()) for _ in range(4)]
    ans = 0
    for i in range(A+1):
        for j in range(B+1):
            for k in range(C+1):
                ans += 500 * i + 100 * j + 50 * k == X
    print(ans)


if __name__ == '__main__':
    main()
