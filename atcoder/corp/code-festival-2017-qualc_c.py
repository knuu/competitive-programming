def main() -> None:
    S = input()
    left, right = 0, len(S) - 1
    ans = 0
    while left < right:
        if S[left] == S[right]:
            left, right = left + 1, right - 1
        elif S[left] == 'x':
            ans += 1
            left += 1
        elif S[right] == 'x':
            ans += 1
            right -= 1
        else:
            print(-1)
            return
    print(ans)


if __name__ == '__main__':
    main()
