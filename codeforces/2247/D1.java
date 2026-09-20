import java.util.*;
import java.util.stream.IntStream;
import java.io.*;
public class D1 {
    final static FastScanner sc = new FastScanner(System.in);
    final static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) {
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) solve();
        System.out.println(sb);
    }
    static void solve() {
        int n = sc.nextInt(), q = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextInt();
        if(IntStream.range(0, n - 1).allMatch(i -> a[i] <= a[i + 1])) {
            sb.append("0\n");
            return;
        }
        for(int x = 1; ; x <<= 1) {
            int max = 0;
            boolean ok = true;
            for(int i = 0; i < n; i += x * 2) {
                int nmax = 0;
                for(int j = i; j < n && j < i + x * 2; j++) {
                    ok &= (a[j] >= max);
                    nmax = Math.max(nmax, a[j]);
                }
                max = Math.max(max, nmax);
            }
            if(ok) {
                sb.append(x + "\n");
                return;
            }
        }
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
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
    public long nextLong() {
        return Long.parseLong(next());
    }
 
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}