import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt(), B = sc.nextInt();
        if (A == B) {
            System.out.println("Draw");
        } else if (A == 1 || (B != 1 && A > B)) {
            System.out.println("Alice");
        } else {
            System.out.println("Bob");
        }
    }
}
