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
using pii = pair<ll, int>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

using al = tuple<ll, ll, int>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<vector<int>> lines(m);
    rep(i, 1, n)
        cin >> arr[i];
    rep(i, 0, m - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        lines[i] = {u, v, w};
    }
    ranges::sort(lines, greater(), [](const vector<int>& a){
        return a[2];
    });
    vector<stack<pii>> sts(n + 1);
    for(auto& l: lines) {
        sts[l[0]].push({l[1], l[2]});
    }
    priority_queue<al, vector<al>, greater<>> pq;
    pq.push({0, arr[1], 1});
    while(!pq.empty()) {
        auto [mi, mx, cur] = pq.top(); pq.pop();
        if(cur == n) {
            cout << mi << endl;
            return;
        }
        while(!sts[cur].empty() && mx >= sts[cur].top().second) {
            auto [v, bi] = sts[cur].top();
            sts[cur].pop();
            pq.push({max(mi, 1ll * bi), mx + arr[v], v});
        }
    }
    cout << -1 << endl;
}

int main() {
    IOS;
    testm;
}
