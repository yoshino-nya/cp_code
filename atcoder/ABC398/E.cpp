// Date: 2025-03-28
// Time: 08:18:34
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dep(n + 1);
    auto dfs = [&](auto &&self, int u, int pre) -> void
    {
        for (auto v : adj[u])
        {
            if (v == pre)
                continue;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    set<pii> st;
    for (int i = 1; i <= n; i++)
    {
        dep = vector<int>(n + 1);
        dfs(dfs, i, 0);
        for (int j = 1; j <= n; j++)
        {
            if ((dep[j] & 1) && (dep[j] > 1))
            {
                if (i > j)
                    st.insert({j, i});
                else
                    st.insert({i, j});
            }
        }
    }
    if (st.size() % 2 == 1)
    {
        cout << "First" << endl;
        auto [x, y] = *st.begin();
        st.erase(st.begin());
        cout << x << " " << y << endl;
    }
    else
        cout << "Second" << endl;
    for (;;)
    {
        int x, y;
        cin >> x >> y;
        if (x == -1)
        {
            return;
        }
        if (x > y)
            swap(x, y);
        assert(st.size());
        st.erase({x, y});
        assert(st.size());
        x = (*st.begin()).first;
        y = (*st.begin()).second;
        cout << x << " " << y << endl;
        st.erase(st.begin());
    }
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