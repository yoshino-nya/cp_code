#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> dp(1 << n);
    dp.back() = 1;
    for(int i = (1 << n) - 1; i >= 0; i--){
        char lst = '#';
        for(int j = 0; j < n; j++){
            if((i >> j & 1) && (s[j] != lst)){
                dp[i ^ (1 << j)] = (dp[i] + dp[i ^ (1 << j)]) % mod;
                lst = s[j];
            }
        }
    }
    cout << dp[0] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}