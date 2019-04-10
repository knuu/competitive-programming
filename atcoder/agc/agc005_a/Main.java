import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        int cnt = 0, diff = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'S') {
                diff++;
            } else if (S.charAt(i) == 'T') {
                diff--;
                if (diff < 0) {
                    cnt++;
                    diff = 0;
                }
            }
        }
        System.out.println(cnt + diff);
    }
}
