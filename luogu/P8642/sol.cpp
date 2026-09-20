// Date: 2025-03-15
// Time: 16:50:38

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> r(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    vector<int> s(n * n), ans;
    for (int i = 1, tot = 0; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            a[i][j] = tot++;
            // cerr<<a[i][j]<<" \n"[j==n];
        }
    vector<pair<int, int>> dirs { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    auto dfs = [&](auto&& self, int i, int j) -> void {
        if (i == n && j == n) {
            // cerr<<i<<" "<<j<<'\n';
            if (count(r.begin() + 1, r.end(), 0) == n && count(c.begin() + 1, c.end(), 0) == n)
                ans = s;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nx = i + dirs[k].first, ny = j + dirs[k].second;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && r[nx] > 0 && c[ny] > 0 && vis[nx][ny] == false) {
                // if(nx==1) cerr<<ny<<'\n';
                r[nx]--, c[ny]--, vis[nx][ny] = true;
                s[a[i][j]] = a[nx][ny];
                self(self, nx, ny);
                r[nx]++, c[ny]++, vis[nx][ny] = false;
            }
        }
    };
    c[1]--, r[1]--, vis[1][1] = true;
    dfs(dfs, 1, 1);
    // for(int i=0;i<n*n;i++)
    //     cerr<<ans[i]<< " ";
    for (int now = 0; ans[now]; now = ans[now])
        cout << now << ' ';
    cout << n * n - 1 << '\n';
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