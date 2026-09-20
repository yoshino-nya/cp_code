#include <bits/stdc++.h>
// #include "/home/skadi/codes/cp_code/template/debug.hpp"

using namespace std;
using ll = long long;

constexpr int N = int(1e7);
int minp[N + 1];
vector<int> primes;
ll ksm(__int128 a, ll b, ll lmt) {
    __int128 res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        if(res > lmt) return - 1;
        a = a * a;
        
        b >>= 1;
        if(a > lmt && b) return - 1;
    }
    return 1;
}
void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 21:30:07
    ll L, R;
    cin >> L >> R;
    // map<int, int> mp;
    ll ans = 1; // L自己肯定是一个
    vector<int> vis(R - L + 1);
    auto get = [&](ll p, ll lmt) {
        // 算 p ^ x <= lmt
        int lo = 0, hi = 51;
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            ll res = ksm(p, mid, lmt);
            // cerr << format("l : {}, r : {}, mid : {}, res : {}\n", lo, hi, mid, res);
            if(res == - 1){ // 大了
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return lo;
    };
    // cerr << get(2, 4) << '\n';
    // return;
    for(int i = 0; i < primes.size() && (ll) primes[i] * primes[i] <= R; i++){
        auto p = primes[i];
        for(ll x = (L + p - 1) / p; x <= R / p; x++)
            vis[x * p - L] = 1; // 标记[L, R] 中的合数
        // if(p > L) continue;
        int l = get(p, L), r = get(p, R);
        // cerr << format("p : {}, l : {}, r : {}\n", p, l , r);
        ans += r - l;
    }
    if(L == 1) ans--;
    else if(vis[0] == 0) ans--;
    for(auto x : vis)
        ans += x == 0;
    cout << ans << '\n';
}
/*
1 12
1 2 6 12 60 60 420 840 
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= N; i++)
    {
        if (minp[i])
            continue;
        minp[i] = i;
        primes.push_back(i);
        if (ll(i) * i > N)
            continue;
        for (ll j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}