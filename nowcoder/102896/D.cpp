// Date: 2025-03-02
// Time: 19:55:55

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    long long now = 0;
    while (t--) {
        long long T;
        cin >> T;
        while (now * now < T)
            now += 2;
        long long x = T - (now - 2) * (now - 2);
        // cerr << x << '\n';
        if (x <= now - 1) {
            cout << -now / 2 + 1 << " " << -now / 2 + x << '\n';
        } else if (x <= 2 * (now - 1)) {
            x -= now - 1;
            cout << -now / 2 + x + 1 << " " << now / 2 - 1 << '\n';
        } else if (x <= 3 * (now - 1)) {
            x -= 2 * (now - 1);
            cout << now / 2 << " " << now / 2 - x - 1 << '\n';
        } else {
            x -= 3 * (now - 1);
            cout << now / 2 - x << " " << -now / 2 << '\n';
        }
    }
}
/*
21 22 23 24 25 26
20             27
19             28
18             29
17             30
36 35 34 33 32 31
*/
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