// Date: 2025-02-24
// Time: 19:33:58

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    int all = 0;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
        for (auto x : s[i])
            if (x == '\\' || x == '/')
                all++;
    }
    // map<char, pair<int, int>> mp;
    vector<pair<int, int>> mp(128);
    mp['N'] = { 1, 0 }, mp['S'] = { -1, 0 };
    mp['W'] = { 0, 1 }, mp['E'] = { 0, -1 };
    // int cnt = 0;
    set<pair<int, int>> st;
    auto dfs = [&](auto&& self, int x, int y, char d) -> void {
        if (x < 0 || x >= r || y < 0 || y >= c)
            return;
        if (s[x][y] == '/') {
            // cnt++;
            st.insert({ x, y });
            if (d == 'N')
                d = 'E';
            else if (d == 'S')
                d = 'W';
            else if (d == 'W')
                d = 'S';
            else
                d = 'N';
        } else if (s[x][y] == '\\') {
            // cnt++;
            st.insert({ x, y });
            if (d == 'N')
                d = 'W';
            else if (d == 'S')
                d = 'E';
            else if (d == 'W')
                d = 'N';
            else
                d = 'S';
        }
        int nx = x + mp[d].first, ny = y + mp[d].second;
        self(self, nx, ny, d);
    };
    vector<string> ans;
    for (int _ = 0; _ < 2; _++) {
        char d = (_ ? 'N' : 'S');
        for (int i = 0; i < c; i++) {
            // cnt = 0;
            st.clear();
            if (d == 'N')
                dfs(dfs, 0, i, d);
            else
                dfs(dfs, r - 1, i, d);
            // cerr<<cnt<<'\n';
            if (st.size() == all) {
                string tmp { d };
                // tmp.push_back('1' + i);
                tmp+=to_string(i+1);
                ans.push_back(tmp);
            }
        }
    }
    for (int _ = 0; _ < 2; _++) {
        char d = (_ ? 'W' : 'E');
        for (int i = 0; i < r; i++) {
            // cnt = 0;
            st.clear();
            if (d == 'W')
                dfs(dfs, i, 0, d);
            else
                dfs(dfs, i, c - 1, d);
            if (st.size() == all) {
                string tmp { d };
                // tmp.push_back('1' + i);
                tmp+=to_string(i+1);
                ans.push_back(tmp);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
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