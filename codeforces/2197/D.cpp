#include <bits/stdc++.h>
using namespace std;

using LL = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    vector<pair<int, int>> vec(n + 1);
    for (int i = 1; i <= n; i++)
        vec[i] = {a[i], i};
    sort(vec.begin() + 1, vec.end());
    set<int> st;
    auto check = [&](LL i, LL j)
    {
        if (i <= 0 || j > n)
            return;
        assert(i < j);
        if (1LL * a[i] * a[j] == j - i && a[i] != a[j])
            ans++;
    };
    for (int i = 1; i <= n; i++)
    {
        for (auto x : st)
        {
            int j = vec[i].second;
            LL y = (1LL * x * vec[i].first - j);
            if (y <= 0)
                continue;
            check(j - y, j);
            check(j, j + y);
        }
        st.insert(vec[i].first);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*

*/