import java.util.*;

public class A {
    private final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        while (n-- > 0) {
            solve();
        }
        sc.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i + 1] > 0) {
                a[i] += a[i + 1];
                ans++;
            }
        }
        if (a[0] > 0) {
            ans++;
        }
        System.out.println(ans);
    }
}