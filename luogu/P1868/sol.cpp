// Date: 2025-04-04
// Time: 13:21:57
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e6 + 10;
int dp[N];

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i <= 3000000; i++)
    {
        while (j < v.size() && v[j].first == i)
        {
            auto [l, r] = v[j];
            j++;
            dp[r] = max(dp[r], (l ? dp[l - 1] : 0) + r - l + 1);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[3000000] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}