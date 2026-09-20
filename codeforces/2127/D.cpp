#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = int(1e9) + 7;
constexpr int N = int(2e5);
int fact[N + 1];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++, d[v]++;
    }
    if(m != n - 1){
        cout << "0\n";
        return;
    }
    int ans = 2, cnt = 0;
    for(int u = 1; u <= n; u++){
        int leaf = 0, not_leaf = 0;
        for(int v : g[u]){
            if(d[v] == 1) leaf++;
            else not_leaf++;
        }
        if(d[u] > 1) cnt++;
        if(not_leaf > 2){
           ans = 0; break;
        }
        ans = 1LL * ans * fact[leaf] % mod;
    }
    if(cnt > 1) ans = 2 * ans % mod;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    fact[0] = 1;
    for(int i = 1; i <= N; i++)
        fact[i] = 1LL * fact[i - 1] * i % mod;
    int T; cin >> T; while(T--)
    {solve();} return 0;
}