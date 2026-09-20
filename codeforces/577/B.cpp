#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-16 11:16:17
void solve(){
    int n, m; cin >> n >> m;
    vector<int> vec(n), vis(m);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        vec[i] %= m;
    }
    if(n >= m){
        cout << "YES\n";
        return;
    }
    for(auto x : vec){
        vector<int> nvis(vis);
        for(int i = 0; i < m; i++){
            nvis[(i + x) % m] |= vis[i];
        }
        nvis[x] = 1;
        vis = nvis;
    }
    cout << (vis[0] ? "YES" : "NO") << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}