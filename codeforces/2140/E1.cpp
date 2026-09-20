#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20][21][2];
void solve()
{
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<int> c(k);
    for(int i = 0; i < k; i++) cin >> c[i];
    if(m == 1){
        cout << "1\n";
        return;
    }
    for(int i = 0; i < (1 << n); i++)
        for(int j = 1; j <= n; j++)
            for(int p = 0; p <= 1; p++)
                dp[i][j][p] = 0;
    dp[1][1][0] = dp[1][1][1] = 1;
    // dp[0][1][0] = dp[0][1][1] = 0;
    auto get = [&](int mask, int x){
        int low = mask & ((1 << (x + 1)) - 1);
        int high = mask - low;
        high >>= 1;
        low &= (1 << x) - 1;
        return high + low;
    };
    for(int i = 2; i <= n; i++){
        for(int mask = 0; mask < (1 << i); mask++){
            dp[mask][i][0] = 1;
            for(auto p : c){
                if(p > i) break;
                auto nmsk = get(mask, p - 1);
                dp[mask][i][1] |= dp[nmsk][i - 1][0];
                dp[mask][i][0] &= dp[nmsk][i - 1][1];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++)
        ans += 1 + dp[i][n][1];
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
10011
10010
*/