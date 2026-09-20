// Date: 2025-03-05
// Time: 18:14:27

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> lst(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i])
            continue;
        if (lst[i - 1] == 1) {
            if (a[i] <= 2)
                continue;
            if (a[i] > 4) {
                ans++;
                continue;
            }
            lst[i] = 3, ans++;
        } else if (lst[i - 1] == 3) {
            if (a[i] > 4) {
                ans++;
                continue;
            }
            ans++;
            lst[i] = 1;
            continue;
        } else {
            if (a[i] <= 2) {
                lst[i] = 1;
                ans++;
            } else
                ans++;
        }
    }
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