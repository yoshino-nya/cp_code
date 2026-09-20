#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x; cin >> x;
    int ans = 0;
    auto calc = [](int x) {
        int s = 0;
        for(auto i : to_string(x))
            s += i - '0';
        return s;
    };
    for(int s = 1; s <= 100; s++){
        int y = x + s;
        if(calc(y) == s) ans++;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    
}