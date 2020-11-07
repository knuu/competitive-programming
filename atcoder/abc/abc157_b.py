def main() -> None:
    board = [[int(x) for x in input().split()] for _ in range(3)]
    N = int(input())
    B = [int(input()) for _ in range(N)]
    bingo = [[False] * 3 for _ in range(3)]
    for b in B:
        for i in range(3):
            for j in range(3):
                if b == board[i][j]:
                    bingo[i][j] = True
    flag = False
    for i in range(3):
        if all(bingo[i][j] for j in range(3)):
            flag = True
        if all(bingo[j][i] for j in range(3)):
            flag = True
    if all(bingo[i][i] for i in range(3)):
        flag = True
    if all(bingo[i][2-i] for i in range(3)):
        flag = True
    print("Yes" if flag else "No")



if __name__ == '__main__':
    main()
