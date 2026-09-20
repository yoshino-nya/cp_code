#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long s, m;
    cin >> s >> m;
    if(s % (m & -m)){
        cout << "-1\n"; return;
    }
    long long lo = 0, hi = s + 1;
    while(lo < hi - 1){
        long long cur = lo + hi >> 1;
        long long res = s;
        for(int p = 59; p >= 0; p--){
            if(m >> p & 1){
                long long x = 1LL << p;
                // res - x * cur
                // res % cur

                // res < x * cur
                // res / x < cur
                if((res + x - 1) / x <= cur)
                    res %= x;
                else
                    res -= x * cur;
                if(res < 0){
                    cerr << "err:" << res << "\n";
                    assert(0);
                }
            }
        }
        if(res) lo = cur;
        else hi = cur;
        
    }
    cout << hi << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}