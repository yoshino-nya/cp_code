#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(1e6) + 10;
int w[N], f[N];
// vector<vector<int>> g;
LL dp[N][2];
int head[N << 1], nxt[N << 1], to[N << 1], ecnt = 1;
void add(int u, int v){
    nxt[ecnt] = head[u], to[ecnt] = v, head[u] = ecnt++;
}

void dfs(int u, int p)
{
    dp[u][0] = 0, dp[u][1] = w[u];
    for(int e = head[u]; e; e = nxt[e]){
        int v = to[e];
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void solve()
{
    int n; cin >> n;
    // g.assign(n + 1, vector<int>());
    for(int i = 1; i <= n; i++) f[i] = i;
    vector<pair<int, int>> vec;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        int x; cin >> x;
        int fi = find(i), fx = find(x);
        if(fi == fx) vec.push_back({i, x});
        else{
            f[fi] = fx;
            // g[x].push_back(i);
            // g[i].push_back(x);
            add(i, x), add(x, i);
        }
    }
    LL ans = 0;
    for(auto [x, y] : vec){
        dfs(x, 0);
        LL tmp = dp[x][0];
        dfs(y, 0);
        ans += max(tmp, dp[y][0]);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}