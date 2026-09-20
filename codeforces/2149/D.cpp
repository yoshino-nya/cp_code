#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;
LL calc(string &s){
    vector<int> L(n), R(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b') cnt++;
        L[i] = cnt;
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'b') cnt++;
        R[i] = cnt;
    }
    LL res = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == 'a') res += min(L[i], R[i]);
    return res;
}
void solve()
{
    cin >> n;
    string s; cin >> s;
    // n = s.size();
    LL ans = calc(s);
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') s[i] = 'b';
        else s[i] = 'a';
    }
    ans = min(ans, calc(s));
    cout << ans << "\n";
}

int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}