import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt();
        int adj[][] = new int[N][N];
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) adj[i][j] = 0;
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            adj[a][b] = adj[b][a] = 1;
        }

        System.out.println(dfs(0, 1, N, adj));
    }

    private static int dfs(int v, int state, int N, int adj[][]) {
        if (state == (1 << N) - 1) return 1;
        int ret = 0;
        for (int i = 0; i < N; i++) {
            if ((state >> i & 1) == 0 && adj[v][i] == 1) {
                ret += dfs(i, state | 1 << i, N, adj);
            }
        }
        return ret;
    }
}
