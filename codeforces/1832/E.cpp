#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
LL a[10], comb[6][6];

void solve()
{
    int n, x, y, m, k;
    cin >> n >> a[1] >> x >> y >> m >> k;
    LL ans = comb[k][1] * a[1] % mod;
    for(int i = 2; i <= k; i++){
        int b = 0;
        a[i] = (1LL * a[i - 1] * x + y) % m;
        for(int j = 1, l = i; j <= i && l >= 1; j++, l--){
            assert(j <= k);
            b = (b + comb[k][j] * a[l] % mod) % mod;
        }
        ans ^= 1LL * i * b;
    }
    for(int i = k + 1; i <= n; i++){
        for(int i = 2; i <= k; i++)
            a[i - 1] = a[i];
        a[k] = (a[k - 1] * x + y) % m;
        int b = 0;
        for(int j = 1, l = k; j <= k && l >= 1; j++, l--){
            assert(j <= k);
            b = (b + comb[k][j] * a[l]) % mod;
        }
        ans ^= 1LL * i * b;
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
            assert(f[x] % (f[y] * f[x - y]) == 0);
            comb[x][y] = f[x] / (f[y] * f[x - y]);
            // cerr << x << " " << y << " " << comb[x][y] << '\n';
        }
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}