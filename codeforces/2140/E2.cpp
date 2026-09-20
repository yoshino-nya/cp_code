#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = int(1e9) + 7;

LL ksm(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, m; cin >> n >> m;
    vector<int> dp(1 << n), ndp(1 << n);
    int k; cin >> k;
    vector<int> c(k);
    for(int i = 0; i < k; i++){
        cin >> c[i];
        c[i]--;
    }
    dp[0] = 0, dp[1] = 1;
    auto get = [&](int mask, int x){
        int low = mask & ((1 << (x + 1)) - 1);
        int high = mask - low;
        high >>= 1;
        low &= (1 << x) - 1;
        return low | high;
    };
    for(int i = 1; i < n; i++){
        for(int mask = 0; mask < 1 << i; mask++)
            ndp[mask] = dp[mask];
        for(int mask = 0; mask < 1 << (i + 1); mask++){
            if((n - i) & 1)
                dp[mask] = 0;
            else dp[mask] = 1;
            for(auto p : c){
                if(p > i) break;
                int nmask = get(mask, p);
                // cerr << mask << " " << p << " " << nmask << '\n';
                if((n - i) & 1) dp[mask] |= ndp[nmask];
                else dp[mask] &= ndp[nmask];
            }
        }
    }
    vector<int> cnt(n + 1);
    for(int mask = 0; mask < (1 << n); mask++){
        if(dp[mask]){
            int g = __builtin_popcount(mask);
            cnt[g]++;
            // cerr << g << '\n';
        }
    }
    int ans = 0;
    for(int x = 1; x <= m; x++){
        for(int y = 0; y <= n; y++){
            ans = (ans + ksm(x - 1, n - y) * ksm(m - x + 1, y) % mod * cnt[y] % mod) % mod;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}