// Date: 2025-02-28
// Time: 13:22:56

#include <bits/stdc++.h>
using namespace std;

int f[120][60][60];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 3; i <= n + m - 1; i++) {
        for (int j = 1; j <= min(m, i); j++) {
            for (int k = 1; k < j; k++) {
                f[i][j][k] = max({ f[i - 1][j - 1][k - 1], f[i - 1][j - 1][k], f[i - 1][j][k - 1], f[i - 1][j][k] });
                if (i > j && i > k && i - j <= n && i - k <= n)
                    f[i][j][k] += a[i - j][j] + a[i - k][k];
            }
        }
    }
    cout << f[n + m - 1][m][m - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}