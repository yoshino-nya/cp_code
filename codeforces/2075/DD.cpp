// Date: 2025-03-17
// Time: 23:26:59

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 4e18 + 1;
ll dp[2][60][60];

void ChatGptDeepSeek()
{
    ll X, Y;
    cin >> X >> Y;
    if (X == Y) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < 59; i++)
        for (int j = 0; j < 59; j++)
            dp[0][i][j] = dp[1][i][j] = inf;
    auto calc = [&](int x, int y) {
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= y; j++)
                dp[0][i][j] = dp[1][i][j] = inf;
        // vector<vector<ll>> dp(x + 1, vector<ll>(y + 1, 4e18 + 1));
        dp[0][0][0] = 0;
        // cerr << dp[0][0] << '\n';
        for (int i = 1; i < 57; i++) {
            for (int xx = 0; xx <= x; xx++)
                for (int yy = 0; yy <= y; yy++) {
                    if (xx + i <= x)
                        dp[1][xx][yy] = min(dp[1][xx + i][yy], dp[0][xx][yy] + (1LL << i));
                    if (yy + i <= y)
                        dp[1][xx][yy] = min(dp[1][xx][yy + i], dp[0][xx][yy] + (1LL << i));
                }
            for (int xx = x; xx >= 0; xx--)
                for (int yy = y; yy >= 0; yy--)
                    dp[0][xx][yy] = dp[1][xx][yy];
        } // 1000
        // cerr << dp[x][y] << '\n';
        return dp[1][x][y];
    };
    vector<int> b1, b2;
    ll tmp = X;
    while (tmp) {
        b1.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b1.begin(), b1.end());
    tmp = Y;
    while (tmp) {
        b2.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b2.begin(), b2.end());
    int len = 0;
    for (int i = 0; i < b1.size() && i < b2.size(); i++) {
        if (b1[i] != b2[i]) {
            len = i;
            break;
        }
        // assert(i <= b1.size() && i <= b2.size());
    }
    ll ans = calc(b1.size() - len, b2.size() - len);

    for (int i = len; i >= 0; i--) {
        ans = min(ans, calc(b1.size() - i, b2.size() - i));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr << __lg(vvv) << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}