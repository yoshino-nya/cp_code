// Date: 2025-03-02
// Time: 20:38:36

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1001;
int cost[N][N][3];

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cost[i][j][0] = cost[i][j][1] = cost[i][j][2] = n * n;
            if (s[i][j] == '*') {
                sx = i, sy = j;
            } else if (s[i][j] == '%') {
                ex = i, ey = j;
            }
        }
    int ans = n * n;
    vector<pair<int, int>> dir { { 1, 0 }, { 0, -1 }, { 0, 1 } };
    auto dfs = [&](auto&& self, int x, int y, int z) {
        if (s[x][y] == '%')
            return;
        if (x == n - 1 || y == m - 1 || y == 0)
            return;
        if (z == 0) {
            int nx = x + dir[z].first, ny = y + dir[z].second;
            if (nx >= n || ny >= m || ny < 0)
                return;
            if (s[nx][ny] == '#') {
                cost[x][y][1] = min(cost[x][y][1], cost[x][y][0] + 1);
                cost[x][y][2] = min(cost[x][y][2], cost[x][y][0] + 1);
                self(self, x, y, 1);
                self(self, x, y, 2);
            }
            cost[nx][ny][0] = min(cost[nx][ny][0], cost[x][y][0] + 1);
            self(self, nx, ny, 0);
        } else {
            int nx = x + dir[z].first, ny = y + dir[z].second;
            if (nx >= n || ny >= m || ny < 0)
                return;
            if (s[nx][ny] == '#') {
                cost[nx][ny][z] = min(cost[nx][ny][z], cost[x][y][z] + 1);
                self(self, nx, ny, z);
            } else {
                cost[nx][ny][0] = min(cost[nx][ny][0], cost[x][y][z] + 1);
                self(self, nx, ny, 0);
            }
        }
    };
    cost[sx][sy][0] = 0;
    dfs(dfs, sx, sy, 0);
    if (min(cost[ex][ey][0], cost[ex][ey][1]) == n * n)
        cout << "-1\n";
    else
        cout << cost[ex][ey] << '\n';
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