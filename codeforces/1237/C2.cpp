#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-11 21:00:46
struct node{
    int x, y, z, id;
};
void solve(){
    int n; cin >> n;
    vector<node> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i + 1;
    }
    sort(p.begin(), p.end(), [](node x, node y){
        if(x.x == y.x) return x.y == y.y ? x.z < y.z : x.y > y.y;
        return x.x < y.x;
    });
    vector<array<int, 2>> ans;
    {
        vector<node> np;
        vector<int> vis(n);
        for(int i = 0; i + 1 < p.size(); i++){
            if(p[i].x == p[i + 1].x && p[i].y == p[i + 1].y){
                ans.push_back({p[i].id, p[i + 1].id});
                vis[i] = vis[i + 1] = 1;
                i++;
            }
        }
        for(int i = 0; i < n; i++)
            if(!vis[i]) np.push_back(p[i]);
        p = np;
    }
    {
        vector<node> np;
        vector<int> vis(p.size());
        for(int i = 0; i + 1 < p.size(); i++){
            if(p[i].x == p[i + 1].x){
                ans.push_back({p[i].id, p[i + 1].id});
                vis[i] = vis[i + 1] = 1;
                i++;
            }
        }
        for(int i = 0; i < vis.size(); i++)
            if(!vis[i]) np.push_back(p[i]);
        p = np;
    }
    for(int i = 0; i < p.size(); i += 2)
        ans.push_back({p[i].id, p[i + 1].id});
    for(auto [x, y] : ans)
        cout << x << " " << y << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}