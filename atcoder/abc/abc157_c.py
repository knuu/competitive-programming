def main() -> None:
    N, M = map(int, input().split())
    conds = []
    for _ in range(M):
        s, c = map(int, input().split())
        conds.append((s, str(c)))
    for i in range(10 ** N):
        if len(str(i)) < N:
            continue
        flag = True
        for s, c in conds:
            if str(i)[s-1] != c:
                flag = False
                break
        if flag:
            print(i)
            break
    else:
        print(-1)


if __name__ == '__main__':
    main()
