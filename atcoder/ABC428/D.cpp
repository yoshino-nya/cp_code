#include <bits/stdc++.h>
using namespace std;

using LL = unsigned long long;
void solve()
{
    LL C, D; cin >> C >> D;
    auto sQRT1 = [](LL x) -> LL {
        LL s = sqrt(x);
        while(s * s < x) s++;
        while(s * s > x) s--; // 向下取整
        return s;
    };
    auto sQRT2 = [](LL x) -> LL {
        LL s = sqrt(x);
        while(s * s > x) s--;
        while(s * s < x) s++;
        return s;
    };
    auto get = [](string s){
        LL res = 0;
        for(auto x : s)
            res = res * 10 + x - '0';
        return res;
    };
    // cerr << sQRT1(484) << '\n';
    LL cur = get("1" + string((int)to_string(C).size() - 1, '0'));
    // cerr << cur << " \n";
    LL ans = 0;
    for( ; cur <= D + C; cur *= 10){
        // max(cur, C + 1) , min(10 * cur - 1, D + C)
        LL L = get(to_string(C) + to_string(max(C + 1, cur)));
        LL R = get(to_string(C) + to_string(min(C + D, cur * 10 - 1)));
        LL sR = sQRT1(R), sL = sQRT2(L);
        if(sR >= sL)
            ans += sR - sL + 1;
        // cerr << L << " " << R << " " << ans << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}