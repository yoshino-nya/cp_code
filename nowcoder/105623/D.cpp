// Date: 2025-03-30
// Time: 20:04:44
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // dp[i] = dp[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (i - 2 >= 0)
            dp[i] = max(dp[i], dp[i - 2]);
        if (i - 3 >= 0)
            dp[i] = max(dp[i - 3], dp[i]);
    }
    cout << dp[n] << '\n';
}
//-1 -1 -1 -1 1
//-1  0 0  0  1
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}