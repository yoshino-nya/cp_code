#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL n, m, k; cin >> n >> m >> k;
    LL lo = 0, hi = 1LL * n * m + 1;
    auto calc = [&](LL num) -> LL {
        LL cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += min(0LL + m, num / i);
        return cnt;
    };
    while(lo < hi - 1){
        LL mid = (lo + hi) >> 1;
        if(calc(mid) >= k) hi = mid;
        else lo = mid;
    }
    cout << hi << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}