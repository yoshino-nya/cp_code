#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k); i <= (n); i++) 
#define srep(i, k, n) for(int i = (k); i >= (n); i--)
#define ump unordered_map
#define ust unordered_set
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

vector<vector<pii>> graph;
vector<int> ps;

ll dfs(int u, int fa) {
    ll ans = 0;
    for(auto [v, w]: graph[u]) if(v != fa) {
        ans += dfs(v, u);
        ans += (ll)abs(ps[v]) * w;
        ps[u] += ps[v];
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    // graph = vector<vector<pii>> (n + 1);
    graph.resize(n + 1);
    ps = vector<int> (n + 1);
    rep(i, 1, n)
        cin >> ps[i];
    rep(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << dfs(1, 0);
}

int main() {
    IOS;
    test;
}
