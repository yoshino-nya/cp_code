#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    int g = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        g = gcd(g, abs(x));
    }
    cout << g << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}