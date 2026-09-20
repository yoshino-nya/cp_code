// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-06
// Time: 14:54:42
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    // vc<pii> stk;
    // queue<pii> q;
    vi a(n + 1);
    // stk.push_back({1, n});
    // q.push({1, n});
    auto cmp = [](pii x, pii y){
        if(x.se - x.fi != y.se - y.fi)
            return x.se - x.fi < y.se - y.fi;
        return x.fi > y.fi;
    };
    priority_queue<pii, vc<pii>, decltype(cmp)>pq(cmp);
    pq.push({1, n});
    int tot = 0;
    while(!pq.empty()){
        // auto [l, r] = stk.back();
        auto [l, r] = pq.top();
        // stk.pop_back();
        pq.pop();
        int mi = ((r - l + 1) & 1) ? (l + r) / 2 : (l + r - 1) / 2;
        a[mi] = ++tot;
        if(l != mi) pq.push({l, mi - 1});
        if(r != mi) pq.push({mi + 1, r});
    }
    for(int  i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}