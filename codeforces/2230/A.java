import java.io.*;
import java.util.*;

public class A {

    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    static void solve() throws IOException {
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        long res = 0;

        if (b <= a * 3) {
            res += n / 3L * b;
            n %= 3;
            if (n > 0) {
                res += Math.min(n * a, b);
            }
        } else {
            res += 1L * n * a;
        }
        System.out.println(res);
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