#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            bool ok = false;
            for(int j = 1; j < k && i - j >= 0; j++){
                if(s[i - j] == '1'){
                    ok = true;
                    break;
                }
            }
            if(!ok) ans++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}