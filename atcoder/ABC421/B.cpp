#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[11];
void solve()
{
    cin >> a[1] >> a[2];
    auto get = [&](string s){
        LL res = 0;
        for(auto x : s)
            res = res * 10 + x - '0';
        return res;
    };
    for(int i = 3; i <= 10; i++){
        string s = to_string(a[i - 1] + a[i - 2]);
        reverse(s.begin(), s.end());
        a[i] = get(s);
    }
    cout << a[10] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}