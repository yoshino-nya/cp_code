#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i) dp[j]++;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * 2ll + dp[i]) % mod;
    cout << (dp[n] - dp[n - 1] + mod) % mod << '\n';
    return 0;
}