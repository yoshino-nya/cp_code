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

constexpr int mod = 998244353;

void ChatGptDeepSeek() // Date: 2025-06-23
{                      // Time: 00:50:17 
    int n, m;
    cin >> n >> m;
    vi a(n + 1), b(m + 1), p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        b[i] = p[b[i]];
    }
    vi stk, L(n + 1), R(n + 1, n + 1);
    for(int i = 1; i <= n; i++){
        while(stk.size() && a[stk.back()] < a[i])
            stk.pop_back();
        
        // if(stk.empty()) L[i] = i;
        if(stk.size())
            L[i] = stk.back() + 1;
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n; i >= 1; i--){
        while(stk.size() && a[stk.back()] < a[i])
            stk.pop_back();
        // if(stk.empty()) R[i] = i;
        if(stk.size())
            R[i] = stk.back() - 1;
        stk.push_back(i);
    }
    dbg(L, R);
    if(L[b[1]] || R[b[m]] <= n){
        cout << "0\n";
        return;
    }
    ll ans = 1;
    for(int i = 1; i < m; i++){
        if(b[i + 1] < b[i]){
            cout << "0\n";
            return;
        }
        int l = max(b[i], L[b[i + 1]] - 1), r = min(R[b[i]], b[i + 1] - 1);
        dbg(l, r);
        ans = ans * (r - l + 1) % mod;
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
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}