import java.io.*;
import java.util.*;

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

public class Main {
    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();

    static int[] computeLps(String s) {
        int[] p = new int[s.length()];
        int j = 0;
        for (int i = 1; i < s.length(); i++) {
            while (s.charAt(i) != s.charAt(j) && j > 0) {
                j = p[j - 1];
            }
            if (s.charAt(i) == s.charAt(j))
                j++;
            p[i] = j;
        }
        return p;
    }

    public static void main(String[] args) throws IOException {
        String s = sc.next();
        String t = sc.next();
        int[] p = computeLps(t);
        for (int i = 0, j = 0; i < s.length(); i++) {
            while (s.charAt(i) != t.charAt(j) && j > 0) {
                j = p[j - 1];
            }
            if (s.charAt(i) == t.charAt(j))
                j++;
            if (j == t.length()) {
                sb.append(i - j + 2 + "\n");
                j = p[j - 1];
            }
        }
        for (int i : p)
            sb.append(i + " ");
        System.out.println(sb);
    }
}
