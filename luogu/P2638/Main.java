import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
    final static FastScanner sc = new FastScanner(System.in);
    final static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        // int t = sc.nextInt(); while (t-- > 0) 
            solve();
        System.out.print(sb);
    }
    static BigInteger calc(int n, int m) {
        BigInteger res = BigInteger.ONE;
        for(int i = 1; i <= m; i++) {
            res = res.multiply(BigInteger.valueOf(n - i + 1)).divide(BigInteger.valueOf(i));
        }
        return res;
    }
    static void solve() {
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        sb.append(calc(n + a, n).multiply(calc(n + b, n)) + "\n");
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