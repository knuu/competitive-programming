def main() -> None:
    a, b = map(int, input().split())
    print("Odd" if a * b % 2 else "Even")


if __name__ == '__main__':
    main()
