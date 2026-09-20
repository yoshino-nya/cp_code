import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in);
    int mod = 1000000007;

    Long ksm(Long a, Long b) {
        Long res = 1L;
        while (b > 0) {
            if (b % 2 == 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    Long Inv(Long x){
        return ksm(1L*x,1L*mod-2);
    }

    void solve() {
        int n = sc.nextInt();
        int a[] = new int[n + 1];
        Long sum = 0L;
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
            sum %= mod;
        }
        Long ans = 0L;
        for (int i = 1; i <= n; i++) {
            ans += a[i] * (sum - a[i]) % mod;
            ans %= mod;
        }
        Long x=1L*n*(n-1)/2%mod;
        System.out.println((ans*Inv(x%mod)%mod*Inv(2L)%mod+mod)%mod);
    }

    void man() {
        int t = sc.nextInt();
        while (t-- > 0)
            solve();
    }

    public static void main(String[] args) {
        new Main().man();
    }
}