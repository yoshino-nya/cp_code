import java.util.*;

public class B {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
    }

    static void solve() {
        int n = sc.nextInt(), x1 = sc.nextInt(), x2 = sc.nextInt(), k = sc.nextInt();
        if (n <= 3) {
            System.out.println(1);
            return;
        }
        if (x1 > x2) {
            int tmp = x2;
            x2 = x1;
            x1 = tmp;
        }
        int ans = Math.min(x2 - x1, n - x2 + x1) + k;
        System.out.println(ans);
    }
}