import java.util.*;

public class B {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }

    private static void solve() {
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);

        int mex = 0, mx = a[n - 1];
        for (int i = 0; i < n; i++) {
            if (a[i] == mex) {
                mex++;
            }
        }

        for (int i = 0; i < mex; i++) {
            a[i] = i;
        }
        for (int i = mex; i < n; i++) {
            a[i] = mx;
        }

        long ans = calc(a, n);

        a[0] = mx;
        for (int i = 1; i <= mex && i < n; i++) {
            a[i] = i - 1;
        }
        ans = Math.max(ans, calc(a, n));
        System.out.println(ans);
    }

    private static long calc(int[] a, int n) {
        boolean[] vis = new boolean[n + 1];
        long ans = 0;
        int mex = 0;
        for (int i = 0, mx = 0; i < n; i++) {
            if (a[i] < n) {
                vis[a[i]] = true;
            }
            while (vis[mex]) {
                mex++;
            }
            mx = Math.max(a[i], mx);
            ans += mex + mx;
        }
        return ans;
    }
}
