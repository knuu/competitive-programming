import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(), maxD = 0;
        int counter[] = new int[N];

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            counter[a]++;
            maxD = Math.max(a, maxD);
        }


        if (maxD % 2 == 0 && counter[maxD / 2] != 1) {
            System.out.println("Impossible");
            return ;
        }
        for (int i = 0; i < (maxD + maxD % 2) / 2; i++) {
            if (counter[i] > 0) {
                System.out.println("Impossible");
                return ;
            }
        }
        for (int i = (maxD + 2 - maxD % 2) / 2; i <= maxD; i++) {
            if (counter[i] < 2) {
                System.out.println("Impossible");
                return ;
            }
        }

        System.out.println("Possible");
    }
}
