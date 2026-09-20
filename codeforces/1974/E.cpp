// Date: 2025-03-17
// Time: 17:33:34

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;
ll dp[1000 * 100 + 1];

void ChatGptDeepSeek()
{
    int m, x;
    cin >> m >> x;
    vector<int> c(m + 1), h(m + 1);
    int n = 0;
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> h[i];
        for (int j = 1; j <= h[i]; j++)
            dp[n + j] = inf;
        n += h[i];
    }
    // vector<ll> dp(1000 * m + 1, inf);

    dp[0] = 0;
    ll have = 0;
    for (int i = 1; i <= m; i++) {
        // vector ndp = dp;
        for (int j = n; j - h[i] >= 0; j--) {
            if (dp[j - h[i]] + c[i] <= have)
                dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
        }
        have += x;
    }
    for (int i = n; i >= 0; i--) {
        if (dp[i] != inf) {
            cout << i << "\n";
            return;
        }
    }
}

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