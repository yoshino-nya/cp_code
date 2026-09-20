import java.util.*;
import java.io.*;
public class D2 {
    final static FastScanner sc = new FastScanner(System.in);
    final static StringBuilder sb = new StringBuilder();
    final static SegTree seg = new SegTree();
    public static void main(String[] args) {
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) solve();
        System.out.println(sb);
    }
    static void solve() {
        int n = sc.nextInt(), q = sc.nextInt();
        int N = 1;
        while(N < n) N <<= 1;
        int[] a = new int[N + 1];
        for(int i = 1; i <= n; i++) a[i] = sc.nextInt();
        for(int i = N; i > n; i--) a[i] = 1_000_000_000;
        seg.build(1, 1, N, a);
        sb.append(seg.ans[1] + "\n");
        while(q-- > 0) {
            int i = sc.nextInt(), val = sc.nextInt();
            seg.update(i + 1, val, N);
            sb.append(seg.ans[1] + "\n");
        }
    }
}

class SegTree {
    int[] max = new int[1_000_001 << 2], min = new int[1_000_001 << 2], ans = new int[1_000_001 << 2];
    void pull(int p, int l, int r) {
        int mid = l + r >> 1;
        min[p] = Math.min(min[p << 1], min[p << 1 | 1]);
        max[p] = Math.max(max[p << 1], max[p << 1 | 1]);
        ans[p] = Math.max(ans[p << 1], ans[p << 1 | 1]);
        if(max[p << 1] > min[p << 1 | 1]) ans[p] = mid - l + 1;
    }
    void update(int p, int l, int r, int i, int val) {
        if(l == r) {
            min[p] = max[p] = val;
            return;
        }
        int mid = l + r >> 1;
        if(i <= mid) update(p << 1, l, mid, i, val);
        else update(p << 1 | 1, mid + 1, r, i, val);
        pull(p, l, r);
    }
    void build(int p, int l, int r, int[] a) {
        if(l == r) {
            min[p] = max[p] = a[l];
            ans[p] = 0;
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pull(p, l, r);
    }
    void update(int i, int val, int n) {
        update(1, 1, n, i, val);
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