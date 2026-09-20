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

// Date: 2025-05-26
// Time: 17:43:01
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    // 这不是很简单，只需要知道每个数在的最大的范围使得他是最大值
    // 感觉两个单调栈就对完了是不是
    vi a(n + 1), l(n + 1, 1), r(n + 1, n);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vi stk;
    for(int i = 1; i <= n; i++){
        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        if(stk.size()) l[i] = stk.back() + 1;
        if(stk.empty() || a[stk.back()] > a[i])
            stk.push_back(a[i]);
    }
    stk.clear();
    for(int i = n; i >= 1; i--){
        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        if(stk.size()) r[i] = stk.back() - 1;
        if(stk.empty() || a[stk.back()] > a[i])
            stk.push_back(a[i]);
    }
    // 不对，，还有相同的数字啊，是不是有点难搞了。。。
    // 看上次出现的地方，会不会重合，以及
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