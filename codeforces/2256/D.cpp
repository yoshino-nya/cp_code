#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 1'000'000;
constexpr int mod = 998'244'353;
int f[N + 5], inv[N + 5];
int ksm(int a, int b)
{
    int res = 1;
    while(b) {
        if(b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}
void init()
{
    f[0] = 1;
    for(int i = 1; i <= N; i++) {
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inv[N] = ksm(f[N], mod - 2);
    for(int i = N - 1; i >= 0; i--)
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m)
{
    return 1LL * f[n] * inv[n - m] % mod * inv[m] % mod;
}
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int pre = -1;
    int cnt[]{0, 0}, seg[]{0, 0};
    for(int i = 0; i < n; i++) {
        int cur = s[i] - '0';
        if(cur != pre) {
            seg[cur]++;
        }
        cnt[cur]++;
        pre = cur;
    }
    // cerr << format("{}, {}, {}, {}\n", cnt[0], cnt[1], seg[0], seg[1]);
    if(cnt[0] == 0 || cnt[1] == 0) {
        cout << "1\n";
        return;
    }
    int ans = 1LL * C(cnt[0] - 1, seg[0] - 1) * C(cnt[1] - 1, seg[1] - 1) % mod;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    int t; cin >> t;
    while(t--) solve();
}