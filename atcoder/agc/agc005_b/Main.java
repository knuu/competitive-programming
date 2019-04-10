import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int A[] = new int[N], rev[] = new int[N];
        long left[] = new long[N], right[] = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            rev[A[i]-1] = i;
        }
        left[0] = -1;
        right[N-1] = N;
        for (int i = 1; i < N; i++) {
            long now = i-1;
            while (now != -1 && A[(int)now] > A[i]) now = left[(int)now];
            left[i] = now;
        }
        for (int i = N-2; i >= 0; i--) {
            long now = i+1;
            while (now != N && A[(int)now] > A[i]) now = right[(int)now];
            right[i] = now;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            long M = right[rev[i]] - left[rev[i]] - 1, R = right[rev[i]] - rev[i] - 1, L = rev[i] - left[rev[i]] - 1;
            ans += (long)(i + 1) * (M * (M + 1) / 2 - L * (L + 1) / 2 - R * (R + 1) / 2);
        }

        System.out.println(ans);
    }
}
