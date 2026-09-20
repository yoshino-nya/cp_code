#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(b >= a){
        if((n - b) % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }else{
        
        if((n & 1) == (a & 1) && (b & 1) == (a & 1)){
            cout << "YES\n";
        }else
            cout << "nO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}