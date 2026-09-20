// Date: 2025-03-17
// Time: 19:56:04

#include <bits/stdc++.h>
using namespace std;

int mp[1001][1001];

void ChatGptDeepSeek()
{
    memset(mp, -1, sizeof mp);
    // cerr<<mp[0][0]<<'\n';
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), y(k), a(k);
    int now = 0;
    // map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i] >> a[i];
        mp[x[i]][y[i]] = i;
        // mp[{ x[i], y[i] }] = i;
        now |= (a[i] << (2 * i));
    }
    // 10 01 10
    // cerr << now << '\n';
    vector<int> dp(now + 1, 666);
    dp[now] = 0;
    vector<pair<int, int>> dir { { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    auto calc = [&](int now_val, int i, int j) {
        for (auto it : dir) {
            int nx = i + it.first, ny = j + it.second;
            if (nx > n || nx < 1 || ny > m || ny < 1)
                continue;
            if (mp[nx][ny] != -1) {
                int xx = (now_val >> (2 * mp[nx][ny])) & 3;
                assert(xx <= 3 && xx >= 0);
                now_val ^= (xx << (2 * mp[nx][ny]));
                xx = max(0, xx - 1);
                now_val |= (xx << (2 * mp[nx][ny]));
            }
        }
        return now_val;
    };
    // k * 2**20
    // k*1e6*5
    for (int i = now; i >= 0; i--) {
        {
            int tmp = i;
            bool skip = false;
            for (int j = 0; j < k; j++) {
                if ((tmp & 3) > a[j]) {
                    skip = true;
                    break;
                }
                tmp >>= 2;
            }
            if (skip)
                continue;
        }
        // cerr<<i<<" "<<dp[i]<<" \n";
        for (int j = 0; j < k; j++) {
            for (auto it : dir) {
                int nx = x[j] + it.first, ny = y[j] + it.second;
                if (nx > n || nx < 1 || ny > m || ny < 1)
                    continue;
                int nxt = calc(i, nx, ny);
                // cerr<<nxt<<'\n';
                dp[nxt] = min(dp[nxt], dp[i] + 1);
            }
        }
    }
    cout << dp[0] << '\n';
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