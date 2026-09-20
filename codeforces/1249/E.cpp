#include <bits/stdc++.h>
using namespace std;

int dp[200005][2];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, c; cin >> n >> c;
    vector<int> a(n), b(n);
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) cin >> b[i];
    dp[1][0] = 0, dp[1][1] = c;
    for(int i = 2; i <= n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
    }
    for(int i = 1; i <= n; i++)
        cout << min(dp[i][0], dp[i][1]) << " \n" [i == n];
    return 0;
}