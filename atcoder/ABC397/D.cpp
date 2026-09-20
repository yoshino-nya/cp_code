// Date: 2025-03-15
// Time: 20:22:09

#include <bits/stdc++.h>
using namespace std;
// using ll = unsigned long long;
using ll = long long;

void ChatGptDeepSeek()
{
    ll n;
    cin >> n;
    /*
    (y+d)*(y+d)*(y+d)-y*y*y=n
    (yyy+3dyy+3ddy+ddd)-yyy=n
    3dyy+3ddy+ddd=n
    3yy+3dy+dd=n/d
    */
    auto calc = [&](ll d) {
        ll lo = 0, hi = 1e9 + 1;
        while (lo < hi - 1) {
            ll mid = (lo + hi) >> 1;
            if (3 * mid * mid + 3 * mid * d + d * d <= n / d)
                lo = mid;
            else
                hi = mid;
        }
        // cerr << d << " " << hi << '\n';

        if (3 * lo * lo + 3 * lo * d + d * d == n / d)
            return lo;
        return 0LL;
    };
    for (ll d = 1; d * d * d <= n; d++) {
        if (n % d == 0) {
            ll res = calc(d);
            if (res) {
                cout << res + d << " " << res << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
} // 100 100 100

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