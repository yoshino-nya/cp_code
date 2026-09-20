#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;
    if(count(s.begin(), s.end(), 'B') == 0){
        for(int i = 1; i <= q; i++){
            int x; cin >> x;
            cout << x << "\n";
        }
    }else{
        for(int i = 1; i <= q; i++){
            int ans = 0, x;
            cin >> x;
            int cur = 0;
            while(x){
                if(s[cur] == 'A') x--;
                else x >>= 1;
                cur = (cur + 1) % n;
                ans++;
            }
            cout << ans << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}