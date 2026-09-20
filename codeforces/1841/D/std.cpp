// Date: 2025-03-20
// Time: 15:18:52

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            if (l[i] > r[j] || l[j] > r[i])
                continue;
            res.push_back({ min(l[i], l[j]), max(r[i], r[j]) });
        }
    sort(res.begin(), res.end(), [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
    int R = -1, ans = 0;
    for (auto [l, r] : res) {
        if (l > R) {
            ans++;
            R = r;
        }
    }
    cout << n - 2 * ans << '\n';
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