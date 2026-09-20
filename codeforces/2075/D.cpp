// 好像直接全部预处理好就行。。。
//  Date: 2025-03-18
//  Time: 11:53:03

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> dp(60, vector<ll>(60, 1e18 + 1));

void ChatGptDeepSeek()
{
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "0\n";
        return;
    }
    vector<int> b1, b2;
    ll tmp = x;
    while (tmp) {
        b1.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b1.begin(), b1.end());
    tmp = y;
    while (tmp) {
        b2.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b2.begin(), b2.end());
    // if(b1.size()>b2.size()) swap(b1,b2);
    // while(b1.size()<b2.size()) b1.push_back()
    int len = 0;
    for (int i = 0; i < b1.size() && i < b2.size(); i++) {
        if (b1[i] != b2[i]) {
            assert(i < b1.size() && i < b2.size());
            // len = i;
            break;
        }
        len++;
    }
    // cerr << len << '\n';
    ll ans = 1e18 + 1;
    for (int i = 0; i <= len; i++) {
        assert(i <= b1.size() && i <= b2.size()); // 哦 没事了 有0
        // 那是哪错了呢？
        // cerr << b1.size() - i << " " << b2.size() - i << " \n";
        ans = min(ans, dp[b1.size() - i][b2.size() - i]);
    }
    // for (int i = 1; i <= 10; i++) {
    //     if (i + b1.size() < 60)
    //         ans = min(ans, dp[b1.size() + i][b2.size()]);
    //     if (i + b2.size() < 60)
    //         ans = min(ans, dp[b1.size()][b2.size() + i]);
    //     if (i + b2.size() < 60 && i + b1.size() < 60)
    //         ans = min(ans, dp[b1.size() + i][b2.size() + i]);
    // }
    ans = min(ans, dp[b1.size() + 1][b2.size()]);
    // cerr << dp[2][2] << " " << dp[1][1] << '\n';
    // 哦哦 没事了 只有有一个被除成0 才能除更多位的
    // 所以如果 dp[b1.size()][b2.size()] 不行
    // 那就试一下它们附近的更大一些的
    cout << ans << '\n';
    // 10 11
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0][0] = 0;
    for (int i = 1; i < 60; i++) {
        vector ndp = dp;
        // for (int x = 59; x >= 0; x--)
        //     for (int y = 59; y >= 0; y--)
        for (int x = 0; x < 60; x++)
            for (int y = 0; y < 60; y++) {
                // 好好好 咋说呢 就是如果到不了 那么就可以直接用更大的数字来除啊
                // @@@@@@@@@@@@
                // 并不行。。。
                if (x >= i)
                    ndp[x][y] = min(ndp[x][y], dp[x - i][y] + (1LL << i));
                if (y >= i)
                    ndp[x][y] = min(ndp[x][y], dp[x][y - i] + (1LL << i));
            }
        dp = ndp;
    }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}