#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int inf = int(1e9);

void solve()
{
    int n; cin >> n;
    vector<int> X(n), Y(n);
    // max x + y, and min -x + y
    LL mx = -int(2e9), mn = int(2e9);
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        mx = max(mx, 0ll + X[i] + Y[i]);
        mn = min(mn, 0ll - X[i] + Y[i]);
    }
    auto ask = [&](char c, int k){
        cout << "? " << c << " " << k << endl;
        LL x; cin >> x;
        return x;
    };
    ask('U', inf), ask('U', inf);
    ask('R', inf);
    LL x1 = ask('R', inf) + mx - 4ll * inf; // X + Y
    /*
    (X + 2inf - xi) + (Y + 2inf - yi) 
    */
    ask('D', inf), ask('D', inf), ask('D', inf);
    LL x2 = ask('D', inf) - mn - 4ll * inf; // X - Y
    /*
    (X + 2inf - xi) + (yi - (Y - 2inf)) 
    X - Y + 4inf + yi - xi
    */
    LL x = (x1 + x2) / 2, y = x - x2;
    cout << "! " << x << " " << y << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}