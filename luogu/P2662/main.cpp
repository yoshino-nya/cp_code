#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool s[3001];
struct node{
    LL dist, id;
};
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        s[x] = true;
        for(int j = 1; j <= min(m, x - 1); j++){
            s[x - j] = true;
            // cerr << x - j << '\n';
        }
    }
    
    vector<int> vec;
    for(int i = 1; i <= 3000; i++){
        if(s[i]){
            for(int j = i * 2; j <= 3000; j += i)
                s[j] = false;
            vec.push_back(i);
        }
    }
    int len = vec[0];
    // for(auto x : vec)
    //     cerr << x << " ";
    // cerr << '\n';
    auto cmp = [&](node x, node y){return x.dist > y.dist;};
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    vector<LL> dis(len, LLONG_MAX);
    dis[0] = 0;
    pq.push({dis[0], 0});
    while(pq.size()){
        auto [dist, id] = pq.top(); pq.pop();
        if(dis[id] < dist) continue;
        for(auto w : vec){  
            LL to = (dist + w) % len;
            if(dis[to] > dist + w){
                dis[to] = dist + w;
                pq.push({dis[to], to});
            }
        }
    }
    LL ans = -1;
    for(int i = 0; i < len; i++){
        if(dis[i] == LLONG_MAX){
            ans = -1;
            break;
        }
        if(dis[i] != i) ans = max(ans, dis[i] - len);
        // cerr << dis[i] << '\n';
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}