// Author: Zhangwuji
// Date: 2025-02-27
// Time: 22:56:49

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/usr/codes/cp/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B' && s[i] != s[i - 1]){
            cnt++;
        }
    }
    if (cnt <= k) {
        cout << "0\n";
        return;
    }
    auto check=[&](int val){
        int res=0;
        bool use=false;
        for(int i=1;i<=n;i++){
            if(s[i]=='B'){
                if(use){
                    continue;
                }else{
                    if(a[i]>val){
                        res++;
                        use=true;
                    }
                }
            }else{
                if(a[i]>val) use=false;
            }
        }
        return res<=k;
    };
    int lo = 0, hi = INF+1;
    while(lo<hi-1){
        int mid=(lo+hi)>>1;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi<<'\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}