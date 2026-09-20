import java.util.*;

public class A {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
    }

    static void solve() {
        int n = sc.nextInt();
        int[] a = new int[3];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            a[x]++;
        }
        int ans = a[0];
        if (a[1] > a[2]) {
            ans += a[2] + (a[1] - a[2]) / 3;
        } else {
            ans += a[1] + (a[2] - a[1]) / 3;
        }
        System.out.println(ans);
    }
}