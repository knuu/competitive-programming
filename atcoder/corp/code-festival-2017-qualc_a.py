def main() -> None:
    S = input()
    print("Yes" if "AC" in [S[i:i+2] for i in range(len(S)-1)] else "No")


if __name__ == '__main__':
    main()
