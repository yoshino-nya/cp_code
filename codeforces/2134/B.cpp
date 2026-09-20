#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k & 1){
        for(int i = 1; i <= n; i++){
            if(a[i] & 1) cout << a[i] + k << " ";
            else cout << a[i] << " ";
        }
        cout << '\n';
    }else if(k == 2){
        for(int i = 1; i <= n; i++){
            while(a[i] % 3) a[i] += 2;
            cout << a[i] << " \n" [i == n];
        }
    }else{
        LL mod = k - 1;
        for(int i = 1; i <= n; i++){
            a[i] += (mod - a[i] % mod) * (mod + 1);
            // assert(a[i] % mod == 0);
            cout << a[i] << " \n"[i == n];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}