// Date: 2025-03-31
// Time: 17:48:26
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 2; i <= n; i++)
    {
        if(adj[i].empty()){
            cout<<"orz\n";
            return;
        }
        // sum+=*min_element(adj[i].begin())
    }
    cout << sum << '\n';
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