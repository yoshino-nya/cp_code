import java.io.*;
import java.util.*;

public class C {

    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    static void solve() throws IOException {
        long a = sc.nextLong();
        int n = sc.nextInt();
        char[] s = Long.toString(a).toCharArray();
        int[] d = new int[n];
        boolean[] have = new boolean[10];
        for (int i = 0; i < n; i++) {
            d[i] = sc.nextInt();
            have[d[i]] = true;
        }
        long[][] dp = new long[s.length + 1][3];
        for (int i = 0; i <= s.length; i++)
            Arrays.fill(dp[i], -1);
        // 0 表示相等，1 表示小于的最大值，2 表示大于的最小值
        dp[0][0] = 0;
        for (int i = 1; i <= 9; i++)
            if (have[i]) {
                dp[0][2] = i;
                break;
            }
        if (a > 0 && s.length > 1)
            dp[1][1] = 0;
        for (int i = 1; i <= s.length; i++) {
            if (dp[i - 1][0] != -1) {
                int x = s[i - 1] - '0';
                if (have[x])
                    dp[i][0] = dp[i - 1][0] * 10 + x;
                for (int j = x - 1; j >= 0; j--) {
                    if (have[j]) {
                        if (dp[i][1] == -1)
                            dp[i][1] = dp[i - 1][0] * 10 + j;
                        else
                            dp[i][1] = Math.max(dp[i][1], dp[i - 1][0] * 10 + j);
                    }
                }
                for (int j = x + 1; j <= 9; j++) {
                    if (have[j]) {
                        if (dp[i][2] == -1)
                            dp[i][2] = dp[i - 1][0] * 10 + j;
                        else
                            dp[i][2] = Math.min(dp[i][2], dp[i - 1][0] * 10 + j);
                    }
                }
            }

            if (dp[i - 1][1] != -1) {
                for (int j = 9; j >= 0; j--)
                    if (have[j]) {
                        if (dp[i][1] == -1)
                            dp[i][1] = dp[i - 1][1] * 10 + j;
                        else
                            dp[i][1] = Math.max(dp[i][1], dp[i - 1][1] * 10 + j);
                    }
            }
            if (dp[i - 1][2] != -1) {
                for (int j = 0; j <= 9; j++)
                    if (have[j]) {
                        if (dp[i][2] == -1)
                            dp[i][2] = dp[i - 1][2] * 10 + j;
                        else
                            dp[i][2] = Math.min(dp[i][2], dp[i - 1][2] * 10 + j);
                    }
            }
        }
        long ans = Long.MAX_VALUE;
        if (dp[s.length][0] != -1)
            ans = 0;

        if (dp[s.length][1] != -1)
            ans = Math.min(a - dp[s.length][1], ans);

        if (dp[s.length][2] != -1)
            ans = Math.min(dp[s.length][2] - a, ans);
        sb.append(ans + "\n");
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(InputStream i) {
        br = new BufferedReader(new InputStreamReader(i));
        st = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

}