// Date: 2025-03-03
// Time: 20:31:37

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    auto work = [](int n, int m, int k) -> string {
        // 让n 大于 m
        // 直接放k个0，
        // 然后如果n-k>m 那么不行

        // 好像也行
        // 不对，应该不行吧，每个都需要一个1来阻挡。

        // 还有其他方式吗？
        string s(k, '0');
        if (k > n || n - k > m) {
            return {};
        }
        n -= k;
        for (int i = k; n && m; i += 2) {
            s += "10";
            n--, m--;
        }
        // m剩下的肯定小于k
        s = string(m, '1') + s;
        return s;
    };
    string ans = (n > m ? work(n, m, k) : work(m, n, k));
    if (n < m) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '0')
                ans[i] = '1';
            else
                ans[i] = '0';
        }
    }
    if (ans.empty())
        cout << "-1\n";
    else
        cout << ans << '\n';
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