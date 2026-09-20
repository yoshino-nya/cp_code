// Date: 2025-03-18
// Time: 15:08:51

// #include "C:/usr/codes/cp/template/debug.hpp"
#include <bits/stdc++.h>

using namespace std;

int board[20][20];
int p[20][20];

constexpr int N = 5e5;
int cnt[N + 1], f[N + 1];
// bool vis[N + 1];
// vector<int> f(9);
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
void ChatGptDeepSeek()
{
    // 看自己上下左右的同色的
    // 如果有 那么加入它们所在的联通块
    // 用并查集维护联通的信息
    //
    // 看它周围的颜色不同的 若气为0了 则该全部移除了
    // 怎么用并查集呢？好像还行 试试 ，其实没用过几次并查集（
    for (int i = 0; i <= 19; i++)
        for (int j = 0; j <= 19; j++)
            board[i][j] = -1;
    int m;
    cin >> m;

    vector<pair<int, int>> dir { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    vector<set<pair<int, int>>> Qi(m + 1, set<pair<int, int>>());

    int res = 0;
    auto Eat = [&](auto&& self, int x, int y, int v) -> void {
        // cerr << x << " " << y << '\n';
        res++;
        assert(x <= 19 && x >= 1 && y <= 19 && y >= 1);
        board[x][y] = -1;
        for (auto it : dir) {
            int nx = x + it.first, ny = y + it.second;
            if (nx > 19 || nx < 1 || ny > 19 || ny < 1 || board[nx][ny] == -1)
                continue;
            if (board[nx][ny] != v) {
                int idx = find(p[nx][ny]);
                assert(idx <= m && idx > 0);

                Qi[idx].insert({ x, y });
            } else
                self(self, nx, ny, v);
        }
    };
    for (int i = 1; i <= m; i++) {
        res = 0;
        int x, y;
        cin >> x >> y;
        board[x][y] = (i % 2);
        p[x][y] = i;
        f[i] = i;

        // 先算周围的反色的气
        for (auto it : dir) {
            int nx = x + it.first, ny = y + it.second;
            if (nx > 19 || nx < 1 || ny > 19 || ny < 1 || board[nx][ny] == -1)
                continue;
            int idx = find(p[nx][ny]);
            // if(!idx) continue;
            assert(idx <= m && idx > 0);

            if (!Qi[idx].empty())
                Qi[idx].erase({ x, y });
            if (p[nx][ny] % 2 != i % 2) {
                // dbg(i, nx, ny);

                if (Qi[idx].empty()) {
                    // dbg(nx, ny, idx);
                    Eat(Eat, nx, ny, p[nx][ny] % 2);
                    // f[idx] = 0;
                }
            }
        }
        for (auto it : dir) {
            int nx = x + it.first, ny = y + it.second;
            if (nx > 19 || nx < 1 || ny > 19 || ny < 1)
                continue;
            if (board[nx][ny] == -1)
                Qi[i].insert({ nx, ny });
        }
        for (auto it : dir) {
            int nx = x + it.first, ny = y + it.second;
            if (nx > 19 || nx < 1 || ny > 19 || ny < 1 || (board[nx][ny] != i % 2))
                continue;
            int idx = find(p[nx][ny]);
            if (idx == i)
                continue;
            assert(idx <= m && idx > 0 && board[nx][ny] == board[x][y]);
            for (auto it : Qi[idx]) {
                // if (board[it.first][it.second] == -1)
                Qi[i].insert(it);
            }
            f[idx] = i;
        }
        // dbg(Qi[i]);
        // cerr << Qi[i].size() << '\n';
        int val = res;
        res = 0;
        if (Qi[i].empty())
            Eat(Eat, x, y, i & 1);
        if (i & 1) {
            cout << res << " " << val << '\n';
        } else {
            cout << val << " " << res << '\n';
        }
        // dbg(Qi[find(1)]);
        // dbg(Qi[2]);
    }
    // 我要哈气了
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