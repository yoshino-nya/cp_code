import java.io.*;
import java.util.*;

public class D {

    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();
    static int[][] st = new int[25][500005];
    static int n;

    public static void main(String[] args) throws IOException {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    static int query(int l, int r) {
        int k = 0;
        {
            int tmp = r - l + 1;
            while(tmp > 0){
                k++;
                tmp >>= 1;
            }
            k--;
        }
        return Math.min(st[k][l], st[k][r - (1 << k) + 1]);
    }

    static void solve() throws IOException {
        // 先找完全一样的 seg 吧，
        // 就是对于每个 i，上一个 ai 如果比 l 小，那就不行
        n = sc.nextInt();
        int[] a = new int[n + 1], b = new int[n + 1];
        for(int i = 1; i <= n; i++) a[i] = sc.nextInt();
        for(int i = 1; i <= n; i++) b[i] = sc.nextInt();
        int[] eq = new int[n + 1], lst1 = new int[n + 1], lst2 = new int[n + 1], mi = new int[n + 1];
        for(int i = 1; i <= n; i++)
            if(a[i] == b[i]) eq[i] = eq[i - 1] + 1;

        // int[][] st = new int[25][500005];

        for(int i = 1; i <= n; i++){
            mi[i] = Math.min(lst1[a[i]], lst2[b[i]]);
            lst1[a[i]] = i; lst2[b[i]] = i;
            st[0][i] = mi[i];
        }
        for(int i = 1; (1 << i) <= n; i++) {
            for(int j = 1; j <= n; j++)
                st[i][j] = Math.min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
        long ans = 0;
        for(int L = 1; L <= n; L++) {
            if(a[L] != b[L]) continue;
            int lo = L, hi = n + 1;
            while(lo < hi - 1) {
                int mid = lo + hi >> 1;
                if(eq[mid] - eq[L] == mid - L) lo = mid;
                else hi = mid;
            }
            int R = lo;
            // [R, RR] 之间的 mi[i] 的最小值都大于等于 L
            lo = R; hi = n + 1;
            while(lo < hi - 1) {
                int mid = lo + hi >> 1;
                // System.err.println("query" + (R + 1) + " " + mid + " " + query(R + 1, mid));
                if(query(R + 1, mid) < L) hi = mid;
                else lo = mid;
            }
            System.err.println(L + " " + R + " " + hi);
            ans += hi - L;
        }
        for(int L = 1; L <= n; L++) {
            if(a[L] == b[L] || mi[L] == 0) continue;
            int lo = L, hi = n + 1;
            while(lo < hi - 1) {
                int mid = lo + hi >> 1;
                // System.err.println("query" + (R + 1) + " " + mid + " " + query(R + 1, mid));
                if(query(L, mid) == 0) hi = mid;
                else lo = mid;
            }
            // System.err.println(L + " " + R + " " + hi);
            // if(hi <= L) continue;
            // ans += hi - L;
        }
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