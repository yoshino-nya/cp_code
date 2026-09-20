#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200005;
constexpr int mod = 998244353;
int dp[N][2][3];
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    /*
    dp[i][x][y]
    第 i 位取 x，和 为 y
    */
    // dp[0][0][0] 
    // ?? 00 01 10 11
    // 0? 01 00 
    for(int x = 0; x < 2; x++) for(int y = 0; y < 3; y++)
        dp[0][x][y] = 0;
    if(s[0] == '?') {
        dp[0][0][2] = 1;
        dp[0][1][2] = 1;
    } else {
        dp[0][s[0] - '0'][2] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int x = 0; x < 2; x++) for(int y = 0; y < 3; y++)
            dp[i][x][y] = 0;
        for(int x = 0; x < 2; x++) {
            for(int y = x; y < 3; y++) {
                if(s[i] == '?') {
                    for(int z = 0; z < 2; z++) {
                        if(x + z == y && i != 1) continue;
                        dp[i][z][x + z] = (dp[i][z][x + z] + dp[i - 1][x][y]) % mod;
                    }
                } else {
                    int z = s[i] - '0';
                    if(z + x == y && i != 1) continue;
                    dp[i][z][x + z] = (dp[i][z][x + z] + dp[i - 1][x][y]) % mod;
                }
            }
        }
    }
    int sum = 0;
    for(int x = 0; x < 2; x++) for(int y = 0; y < 3; y++)
        sum = (sum + dp[n - 1][x][y]) % mod;
    cout << sum << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}