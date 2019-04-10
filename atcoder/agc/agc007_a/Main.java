import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int H = sc.nextInt(), W = sc.nextInt();
        int board[][] = new int[H][W];
        for (int i = 0; i < H; i++) {
            String row = sc.next();
            for (int j = 0; j < W; j++) {
                board[i][j] = row.charAt(j) == '#' ? 1 : 0;
            }
        }

        int r = 0, c = 0;
        while (true) {
            board[r][c] = 0;
            if (r == H-1 && c == W-1) {
                break;
            } else if (r + 1 < H && board[r+1][c] == 1) {
                r++;
            } else if (c + 1 < W && board[r][c+1] == 1) {
                c++;
            } else {
                System.out.println("Impossible");
                return;
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] == 1) {
                    System.out.println("Impossible");
                    return ;
                }
            }
        }
        System.out.println("Possible");
    }
}
