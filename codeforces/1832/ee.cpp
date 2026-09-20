#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
LL a[11], comb[6][6];

LL C(int n, int m)
{
    if(n < m) return 0;
    return comb[n][m];
}
void solve()
{
    int n, x, y, m, k;
    cin >> n >> a[1] >> x >> y >> m >> k;
    LL ans = C(k, 1) * a[1] % mod;
    for(int i = 2; i <= n; i++){
        a[i] = (1LL * a[i - 1] * x + y) % m;
        LL b = 0;
        for(int j = i, l = 1; j >= 1; j--, l++){
            if(l > k) continue;
            assert(l == i - j + 1);
            b = (b + C(k, i - j + 1) * a[j] % mod) % mod;
        }
        // b %= mod;
        ans = ans ^ (1LL * i * b);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int f[6];
    f[0] = 1;
    for(int i = 1; i <= 5; i++)
        f[i] = f[i - 1] * i;
    for(int x = 1; x <= 5; x++)
        for(int y = 1; y <= x; y++){
            comb[x][y] = f[x] / f[y] / f[x - y];
            // cerr << x << " " << y << " " << comb[x][y] << '\n';
        }
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}