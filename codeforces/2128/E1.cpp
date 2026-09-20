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

void ChatGptDeepSeek() // Date: 2025-07-29
{                      // Time: 11:12:16 
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int L = 0, R = 0;
    auto check = [&](int x){
        vi pre(n + 1), mp(2 * n + 1, n + 1);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1];
            if(a[i] < x) pre[i]--;
            else pre[i]++;
        }
        int min_val = 0;
        for(int i = n; i >= 0; i--)
            mp[pre[i] + n] = i;
        for(int i = k; i <= n; i++){
            cmin(min_val, pre[i - k]);
            if(pre[i] > min_val){
                L = mp[min_val + n] + 1;
                R = i;
                return true;
            }
            // cmin(mp[pre[i] + n], i);
        }
        return false;
    };
    int lo = 0, hi = n + 1;
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}