#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    if(s[1] != p[n]){
        cout << "NO\n";
        return;
    }
    for(int i = 1; i < n; i++){
        if((p[i] % p[i + 1]) || (s[i + 1] % s[i])){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 1; i < n; i++){
        if(gcd(p[i], s[i + 1]) != p[n]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}