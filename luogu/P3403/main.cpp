#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
    LL dist, id;
};
void solve()
{
    LL h;
    int x, y, z;
    cin >> h >> x >> y >> z;
    --h;
    vector<LL> dis(x, LLONG_MAX);
    dis[0] = 0;
    auto cmp = [&](node x, node y){
        return x.dist > y.dist;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    pq.push({dis[0], 0});
    while(!pq.empty()){
        auto [dist, id] = pq.top(); pq.pop();
        if(dis[id] < dist) continue;
        int to = (dist + x) % x;
        if(dis[to] > dist + x){
            dis[to] = dist + x;
            pq.push({dis[to], to});
        }
        to = (dist + y) % x;
        if(dis[to] > dist + y){
            dis[to] = dist + y;
            pq.push({dis[to], to});
        }
        to = (dist + z) % x;
        if(dis[to] > dist + z){
            dis[to] = dist + z;
            pq.push({dis[to], to});
        }
    }
    LL ans = 0;
    for(int i = 0; i < x; i++){
        // cerr << dis[i] << " ";
        if(dis[i] <= h)
            ans += (h - dis[i]) / x + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}