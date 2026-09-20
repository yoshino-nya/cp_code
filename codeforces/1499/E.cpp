#include<bits/stdc++.h>
using namespace std;
// created: 2025-10-14 08:19:17
int dp[1024][1024][2];
constexpr int mod = 998244353;
void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
void solve(){
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    x = " " + x, y = " " + y;
    dp[1][0][0] = dp[0][1][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0][0] = (x[i] == x[i - 1] ? 1 : dp[i - 1][0][0] + 1);
    }
    for(int j = 2; j <= m; j++)
        dp[0][j][1] = (y[j] == y[j - 1] ? 1 : dp[0][j - 1][1] + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] != y[j]){
                add(dp[i][j][0], dp[i - 1][j][1]);
                add(dp[i][j][1], dp[i][j - 1][0]);
                if(i > 1)
                    add(dp[i][j][0], dp[0][j][1]);
                if(j > 1)
                    add(dp[i][j][1], dp[i][0][0]);
            }
            if(x[i] != x[i - 1]){
                add(dp[i][j][0], dp[i - 1][j][0]);
            }
            if(y[j] != y[j - 1]){
                add(dp[i][j][1], dp[i][j - 1][1]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        add(ans, dp[i][j][0]), add(ans, dp[i][j][1]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}