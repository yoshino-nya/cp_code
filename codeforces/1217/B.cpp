#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 17:56:51
void solve(){
    int n, x; cin >> n >> x;
    vector<int> d(n), h(n);
    int mx1 = 0, mx2 = 0;
    for(int i = 0; i < n; i++){
        cin >> d[i] >> h[i];
        mx1 = max(d[i], mx1);
        mx2 = max(d[i] - h[i], mx2);
    }
    if(x <= mx1)
        cout << "1\n";
    else{
        if(mx2 == 0) cout << "-1\n";
        else
            cout << (x - mx1 + mx2 - 1) / mx2 + 1 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}