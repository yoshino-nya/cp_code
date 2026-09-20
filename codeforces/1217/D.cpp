#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 16:51:37
vector<vector<pair<int, int>>> g;
int ans[5005];
void solve(){
    int n, m; cin >> n >> m;
    g = vector<vector<pair<int, int>>> (n + 1);
    vector<int> du(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        if(u < v) ans[i] = 1;
        else ans[i] = 2;
        g[u].emplace_back(v, i);
        du[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!du[i]) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto [v, _] : g[u]){
            if(du[v]){
                if(--du[v] == 0)
                    q.push(v);
            }
        }
    }
    if(*max_element(du.begin(), du.end()) == 0){
        cout << "1\n";
        for(int i = 1; i <= m; i++)
            cout << "1 ";
        cout << "\n";
    }else{

        cout << "2\n";
        for(int i = 1; i <= m; i++)
            cout << ans[i] << " \n" [i == m];
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    {solve();} return 0;
}