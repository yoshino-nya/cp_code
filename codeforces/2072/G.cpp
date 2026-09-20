#include <bits/stdc++.h>
using namespace std;

// #define int long long
constexpr int N = 3e5;
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;
//六百六十六 mod 取错了。。。

vector<long long> s1(N + 1);

void solve()
{
    int n;
    long long k;
    cin >> n >> k;
    // pn-p*p*(n/p)+n/p
    long long ans = 0;
    if (k > n) {
        ans += ((k - n) % mod) * n % mod;
        k = n;
    }
    for (int i = 2; i <= k; i++) {
        if (1LL * i * i <= n) {
            vector<int> v;
            int x = n;
            while (x) {
                v.push_back(x % i);
                x /= i;
            }
            for (auto j : v)
                x = x * i + j;
            ans = (ans + x) % mod;
        } else {
            int L = i;
            auto calc = [](int l, int r) {
                return 1LL * (r - l + 1) * (l + r) / 2 % mod;
            };
            while (L <= k) {
                int R = n / (n / L);
                if (R > k)
                    R = k;
                ans = (ans - ((s1[R] - s1[L - 1]) % mod) * (n / L) % mod) % mod;
                ans = (ans + 1LL * calc(L, R) * n % mod) % mod;
                ans = (ans + 1LL * (R - L + 1) * (n / L) % mod) % mod;
                ans = (ans + mod) % mod;

                L = R + 1;
            }
            break;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= N; i++)
        s1[i] = (s1[i - 1] + 1LL * i * i % mod) % mod;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
