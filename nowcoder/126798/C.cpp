#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if(s.front() >= '5')
        cout << "1" + string(n, '0');
    else{
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] >= '5'){
                ans.back() += 1;
                break;
            }else
                ans.push_back(s[i]);
        }
        if(ans.size() == n) ans.back() = '0';
        while(ans.size() < n) ans += '0';
        cout << ans << '\n';
    }
}
// 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}