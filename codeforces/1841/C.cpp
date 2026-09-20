// Date: 2025-03-19
// Time: 11:24:16

#include <bits/stdc++.h>
using namespace std;

constexpr int val[] { 1, 10, 100, 1000, 10000 };
void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    vector<vector<int>> dp(2, vector<int>(5, -1e9 + 1));
    dp[0][0] = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        vector ndp = vector<vector<int>>(2, vector<int>(5, -1e9 + 1));
        int x = s[i] - 'A';
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                ndp[1][max(k, j)] = max(ndp[1][max(k, j)], dp[0][j] + (k < j ? -1 : 1) * val[k]);
            }
            ndp[0][max(x, j)] = max(ndp[0][max(x, j)], dp[0][j] + (x < j ? -1 : 1) * val[x]);
            ndp[1][max(x, j)] = max(ndp[1][max(x, j)], dp[1][j] + (x < j ? -1 : 1) * val[x]);
        }
        dp = ndp;
    }
    cout << max(*max_element(dp[0].begin(), dp[0].end()), *max_element(dp[1].begin(), dp[1].end())) << '\n';
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