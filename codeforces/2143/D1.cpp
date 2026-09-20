#include<bits/stdc++.h>
using namespace std;
// created: 2025-10-13 09:21:09
int dp[305][305][305];
constexpr int mod = 1000000007;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int x = 0; x <= n; x++)
            for(int y = 0; y <= x; y++)
                dp[i][x][y] = dp[i - 1][x][y];
        for(int x = 0; x <= n; x++)
            for(int y = 0; y <= x; y++){
                if(a[i] >= x){
                    dp[i][a[i]][y] = (dp[i][a[i]][y] + dp[i - 1][x][y]) % mod;
                }else if(a[i] >= y){
                    dp[i][x][a[i]] = (dp[i][x][a[i]] + dp[i - 1][x][y]) % mod;
                }
            }
    }
    int ans = 0;
    for(int x = 0; x <= n; x++)
        for(int y = 0; y <= x; y++)
            ans = (ans + dp[n][x][y]) % mod;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}