// Date: 2025-03-05
// Time: 20:32:06

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> A(1), c(1);
    sort(a.begin() + 1, a.end());
    for (int i = 1, cnt = 0; i <= n; i++) {
        cnt++;
        if ((i == n) || (a[i + 1] != a[i])) {
            A.push_back(a[i]);
            c.push_back(cnt);
            cnt = 0;
        }
    }
    n = A.size() - 1;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 6666));
    vector<int> dp(n + 1, 6666);
    dp[0] = 0;
    cerr << n << '\n';
    for (int i = 1; i <= n; i++) {
        vector ndp = dp;
        for (int j = 1; j <= i; j++) {
            // if (dp[j - 1] == 6666)
            //     break;
            if (dp[j - 1] + c[i] <= i - j)
                ndp[j] = min(dp[j - 1] + c[i], dp[j]);
        }
        dp = ndp;
    }
    for (int i = n; i >= 0; i--) {
        if (dp[i] != 6666) {
            cout << n - i << '\n';
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
        solve();
    return 0;
}