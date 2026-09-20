// Date: 2025-03-12
// Time: 08:59:30

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//虽然这可能无法覆盖所有情况，但或许能通过示例测试

void ChatGptDeepSeek()
{
    int n, d;
    ll c;
    cin >> n >> c >> d;
    vector<ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<>());
    // for (int i = 1; i <= n; i++)
    //     a[i] += a[i - 1];
    // if (*max_element(a.begin() + 1, a.end()) >= c) {
    //     cout << "Infinity\n";
    //     return;
    // }
    int lo = -1, hi = d + 1;
    auto check = [&](int k) {
        // 不是。。
        ll sum = 0;
        for (int i = 1, j = 1; i <= d; i++, j++) {
            if (j <= n)
                sum += a[j];
            j %= (k + 1);
        }
        // cerr << sum << '\n';
        return sum >= c;
    };
    while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        // cerr<<mid<<'\n';
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    if (lo == -1)
        cout << "Impossible\n";
    else if (lo == d)
        cout << "Infinity\n";
    else
        cout << lo << '\n';
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}