// Date: 2025-03-17
// Time: 22:40:50

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == 1 && n > 2) {
        int mx = *max_element(a.begin() + 2, a.begin() + n);
        cout << max(mx + max(a[1], a[n]), a[1] + a[n]) << '\n';
        return;
    }
    sort(a.begin() + 1, a.end(), greater<>());
    ll sum = 0;
    for (int i = 1; i <= k + 1; i++)
        sum += a[i];
    cout << sum << '\n';
    // x x x x
}

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