// Date: 2025-02-24
// Time: 17:10:34

#include <bits/stdc++.h>
// #include "C:/usr/codes/CP/template/debug.hpp"
using namespace std;

constexpr int N = 2e6;

struct Fenwick {
    vector<int> b;
    Fenwick()
    {
        // b.resize(N+1,0);
        b = vector<int>(N + 1);
    }
    int lowbit(int x) { return (x) & (-x); }
    void upd(int i, int x)
    {
        while (i <= N) {
            // dbg(i);
            b[i] += x;
            i += lowbit(i);
        }
    }
    int ask(int i)
    {
        int res = 0;
        while (i) {
            // cerr<<"ask: "<<i<<" "<<b[i]<<'\n';
            res += b[i];
            i -= lowbit(i);
        }
        // cerr<<"res: "<<res<<'\n';
        return res;
    }
    int query(int l, int r)
    {
        return ask(r) - ask(l - 1);
    }
};

void solve()
{
    Fenwick C;
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 4>> q(m);
    for (int i = 0; i < m; i++)
        cin >> q[i][0] >> q[i][1] >> q[i][2], q[i][3] = i;
    sort(q.begin(), q.end(), greater<>());
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    vector<int> ans(m);
    for (int i = 1; i <= n; i++) {
        // cerr<<"i: "<<i<<'\n';
        while (!q.empty() && q.back()[0] == i) {
            auto [x, y, z, j] = q.back();
            // cerr<<"q: "<<z<<" "<<j<<'\n';
            q.pop_back();
            // dbg(adj);
            // dbg(q);
            ans[j] -= C.ask(z);
            adj[y].push_back({ z, j });
        }
        // dbg("yuanshen");
        // dbg(adj);
        C.upd(a[i], 1);
        for (auto [x, j] : adj[i]) {
            // cerr<<" adj: "<<x<<" "<<j<<'\n';
            ans[j] += C.ask(x);
        }
    }
    for (auto x : ans)
        cout << x << "\n";
    // cout<<'\n';
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
