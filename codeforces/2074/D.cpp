// Date: 2025-03-11
// Time: 22:52:12

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m * 2 + 1), x(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    set<pair<int, int>> st;
    auto Insert = [&](int X, int Y) {
        auto it = st.lower_bound({ X, 0 });
        if (it == st.end() || it->first != X) {
            st.insert({ X, Y });
        } else {
            if (Y > it->second) {
                st.erase(it);
                st.insert({ X, Y });
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = x[i] - r[i]; j <= x[i] + r[i]; j++) {
            //(j-x[i])*(j-x[i])+y*y<=r*r
            // 可以知道y的范围
            int y = sqrt(1LL * r[i] * r[i] - 1LL * (j - x[i]) * (j - x[i]));
            Insert(j, y);
        }
    }
    long long sum = 0;
    for (auto [X, Y] : st) {
        sum += 2 * Y + 1;
    }
    cout << sum << '\n';
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