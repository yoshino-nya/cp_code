// Date: 2025-03-15
// Time: 15:14:46

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    // 如果有多个1在同一行
    // 我们是没有办法让他们不在同一行的
    // 因为我们每次只能移动一整行 或者去调整列
    // 所以我们只需要去调整行或者列 因为一列上的多个的1 我们也没办法分开他们
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                adj[i].push_back(j);
            }
        }
    vector<int> matched(n + 1);
    vector<bool> sel(n + 1);
    auto dfs = [&](auto&& self, int u) -> bool {
        for (auto v : adj[u]) {
            if (matched[v] && !sel[v]) {
                sel[v] = true;
                if (self(self, matched[v])) {
                    matched[v] = u;
                    return true;
                }
            } else if (!sel[v]) {
                sel[v] = true;
                matched[v] = u;
                return true;
            }
        }
        return false;
    };
    for (int i = 1; i <= n; i++) {
        sel = vector<bool>(n + 1);
        if (!dfs(dfs, i)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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