import java.io.*;
import java.util.*;

public class B {

    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    static void solve() throws IOException {
        // 不能包含 4，
        // 2 前面不能有 1 和 3
        // 2222 1313131
        String ss = sc.next();
        char[] s = ss.toCharArray();
        int n = s.length;
        int[] pre = new int[n], suf = new int[n];
        if (s[0] == '2') pre[0] = 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (s[i] == '2' ? 1 : 0);
        }
        int len = pre[n - 1], cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1' || s[i] == '3') cnt++;
            int cur = cnt + (i > 0 ? pre[i - 1] : 0);
            len = Math.max(len, cur);
        }
        // System.err.println(len);
        sb.append(n - len + "\n");
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