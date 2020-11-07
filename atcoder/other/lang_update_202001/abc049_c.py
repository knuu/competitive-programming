def main() -> None:
    S = input()
    idx = len(S)
    while idx > 0:
        for s in ["dreamer", "eraser", "dream", "erase"]:
            if idx - len(s) >= 0 and s == S[idx-len(s):idx]:
                idx -= len(s)
                break
        else:
            print("NO")
            return
    print("YES")


if __name__ == '__main__':
    main()
