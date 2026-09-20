/*
对于每一个元素
我们知道与它相交的元素的对数
那么要么从与它相交的里面 选出1个和它自己组成一个
要么把自己给删掉

dp[i]表示当前已经弄出来i个元素 且r最小
*/
// Date: 2025-03-20
// Time: 13:48:44

#include <bits/stdc++.h>
// #include "C:/usr/codes/cp/template/debug.hpp"
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9 + 1));
    vector<int> ans(n + 1, 0);
    ans[0] = 0;
    dp[0][0] = -1;
    // dp[i][j]表示答案是j 的最小的 r
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        ans[i] = max(ans[i - 1], ans[i]);
        // if (a[i].second < a[i + 1].first)
        //     continue;
        /* 去前面找和自己相交的 */
        for (int j = 1; j < i; j++) {
            assert(ans[i] >= ans[j]);

            if (a[j].second < a[i].first)
                continue;
            for (int k = 0; k <= ans[j]; k++) {
                if (dp[j][k] < a[j].first) {
                    dp[i][k + 1] = min(dp[i][k + 1], max(a[i].second, a[j].second));
                    ans[i] = max(ans[i], k + 1);
                }
            }
        }

        for (int j = 1; j <= ans[i]; j++)
            assert(dp[i][j] <= dp[i][j + 1]);
    }
    cout << n - ans[n] * 2 << '\n';
    // cout << n << '\n';
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