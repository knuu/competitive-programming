def main() -> None:
    _ = int(input())
    A = [int(x) for x in input().split()]
    A.sort(reverse=True)
    print(sum(A[::2]) - sum(A[1::2]))


if __name__ == '__main__':
    main()
