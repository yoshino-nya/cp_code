/*
path: ~/Projects/cp_code/Codeforces/2242/D.java
date: 2026-07-22 02:14:06
*/
import java.util.*;
import java.io.*;

public class D {
    final static FastScanner sc = new FastScanner(System.in);
    final static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        int t = sc.nextInt(); while (t-- > 0) 
            solve();
        System.out.print(sb);
    }

    static void solve() {
        char[] ca = sc.next().toCharArray(), cb = sc.next().toCharArray();
        int n = ca.length, m = cb.length;
        int[] a = new int[n + 1], b = new int[m + 1];
        for(int i = 1; i <= n; i++)
            a[i] = (ca[i - 1] - '0' + a[i - 1]) % 10;
        for(int i = 1; i <= m; i++)
            b[i] = (cb[i - 1] - '0' + b[i - 1]) % 10;
        if(a[n] != b[m]) {
            sb.append("-1\n");
            return;
        }
        int[][] dp = new int[n + 1][m + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                if(a[i] == b[j])
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        sb.append(dp[n][m] + "\n");
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(InputStream i) {
        br = new BufferedReader(new InputStreamReader(i));
        st = new StringTokenizer("");
    }

    public String next() {
        try {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() { return Integer.parseInt(next()); }
    public long nextLong() { return Long.parseLong(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
}