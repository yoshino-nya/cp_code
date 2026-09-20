// Date: 2025-03-10
// Time: 20:50:43

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ST {
    vector<vector<ll>> st;
    ST(vector<ll>& a)
    {
        st = vector<vector<ll>>(a.size(), vector<ll>(25));
        for (int i = 0; i < a.size(); i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; (1 << j) < a.size(); j++) {
            for (int i = 0; i + (1 << j) <= a.size(); i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        if (l == r)
            return st[l][0];
        int k = __lg(r - l);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
void ChatGptDeepSeek()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> f(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> f[i] >> s[i];
    ST C(s);
    ll sum = 0;
    int ans = 1e9;
    multiset<int> st;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        sum += f[i];
        while (!q.empty() && sum - f[q.front()] >= m) {
            // cerr<<q.front()<<'\n';
            sum -= f[q.front()];
            // st.erase(st.lower_bound(s[q.front()]));
            q.pop();
        }
        // cerr << sum << '\n';
        st.insert(s[i]), q.push(i);
        if (sum >= m) {
            ans = min(ans, C.query(q.front(), i));
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
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}