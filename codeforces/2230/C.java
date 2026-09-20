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
        // 
        int n = sc.nextInt();
        long A = 0, B = 0, C = 0, sum = 0, cnt = 0;
        int[] c = new int[n];
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            c[i] = x;
            if(x == 1) A += 1;
            else {
                B +=  (x - 2) / 2;
                if((x % 2 == 1) && x > 4)
                    C = 1;
                cnt++;
            }
            sum += x;
        }
        A -= B;
        if(A > 0 && cnt == 1) sum++;
        
        long ans = sum - Math.max(A, 0);
        if(ans < 3) ans = 0;
        sb.append(ans + "\n");
        // 1 1 2 1 1 3 3 2 3 3 
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