def main() -> None:
    S = [1 if s == "R" else -1 for s in input()]
    N = len(S)
    ans = [0] * N
    for i in range(N-1):
        if S[i] == 1 and S[i+1] == -1:
            left, right = i, i+1
            while left >= 0 and S[left] == 1:
                ans_idx = i if (i - left) % 2 == 0 else i+1
                ans[ans_idx] += 1
                left -= 1
            while right < N and S[right] == -1:
                ans_idx = i+1 if (right - i - 1) % 2 == 0 else i
                ans[ans_idx] += 1
                right += 1
    print(*ans)


if __name__ == '__main__':
    main()
