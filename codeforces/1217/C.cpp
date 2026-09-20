#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 17:19:46
void solve(){
    string s; cin >> s;
    int cnt = 0;
    int ans = 0;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            cnt++;
            continue;
        }
        int now = 0;
        for(int j = 0; j <= 20 && i + j < s.size(); j++){
            now = now * 2 + s[i + j] - '0';
            // cerr << now << " " << cnt <<  
            if(now >= j + 1 && now <= j + 1 + cnt) ans++; 
        }
        cnt = 0;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}