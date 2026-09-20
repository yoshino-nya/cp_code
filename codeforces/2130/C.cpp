#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> g(2 * n + 1);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        g[l].push_back({r, i + 1});
    }
    vector<int> ans;
    for(int i = 1; i <= 2 * n; i++){
        ranges::sort(g[i], [](array<int, 2> x, array<int, 2> y){
            return x[0] > y[0];
        });
        if(g[i].size())
            ans.push_back(g[i][0][1]);
    }
    cout << ans.size() << '\n';
    ranges::sort(ans);
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}