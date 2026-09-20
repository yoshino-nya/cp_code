// Date: 2025-03-08
// Time: 20:08:05

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end(), greater<>());
    sort(b.begin() + 1, b.end(), greater<>());
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        // a[i] = max(a[i - 1], a[i - 1] + a[i]);
        // cerr << a[i] << " \n"[i == n];
    }
    while (b.size() <= n)
        b.push_back(0);
    for (int i = 1; i <= n; i++) {
        b[i] = max(b[i - 1], b[i - 1] + b[i]);
        // cerr << b[i] << " \n"[i == n];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] + b[i]);
    }
    cout << ans << '\n';
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