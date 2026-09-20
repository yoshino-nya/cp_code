// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/codes/cp_code/template/debug.hpp"
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

ll a[18], b[18];
void ChatGptDeepSeek() // Date: 2025-08-21
{                      // Time: 23:22:21 
    auto get = [&](ll lmt){
        int len = to_string(lmt).size();
        ll sum = 0;
        for(int i = 1; i < len; i++){
            sum += (a[i] - a[i - 1]) * i;
        }
        sum += len * (lmt - a[len - 1] + 1);
        return sum;
    };
    ll k; cin >> k;
    ll lo = 0, hi = 1e14;
    while(lo < hi - 1){
        ll mid = (lo + hi) >> 1;
        if(get(mid) <= k) lo = mid;
        else hi = mid;
    }
    auto work = [&](ll lmt){
        // 求数位和
        string s = to_string(lmt);
        int len = s.size();
        ll res = 0, pre = 0, sc = 45;
        res += b[len - 1];
        // cerr << "res : " << res << '\n';
        for(int i = 0; i < len; i++){
            int j = 0, x = s[i] - '0';
            if(i == 0) j = 1;
            for(j; j < x; j++){
                // 后面几位随便取
                // 自己这一位也要算上
                res += b[len - i - 1] + (pre + j) * a[len - i - 1];
            }
            pre += x;
        }
        res += pre;
        return res;
    };
    // cerr << lo << '\n';
    // cerr << work(lo) << '\n';
    // cerr << work(100) << '\n';
    ll ans = work(lo), sum = get(lo);
    string s = to_string(lo + 1);
    for(int i = 0; i < k - sum; i++){
        ans += s[i] - '0';
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    a[0] = 1;
    for(int i = 1; i <= 18; i++)
        a[i] = a[i - 1] * 10;
    b[1] = 45;
    ll x = 10;
    for(int i = 2; i <= 18; i++){
        b[i] = i * x * 45;
        x *= 10;
    }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}