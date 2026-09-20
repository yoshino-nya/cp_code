#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> suf(n + 2), mx(n + 1);
    for(int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + a[i];
    for(int i = 1; i <= n; i++)
        mx[i] = max(mx[i - 1], a[i]);
    for(int i = 1; i <= n; i++){
        cout << mx[n - i + 1] + suf[n - i + 2] << " \n"[i == n];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t--)
        solve();
    return 0;
}