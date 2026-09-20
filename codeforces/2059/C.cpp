// Author: Zhangwuji
// Date: 2025-02-03
// Time: 01:49:19

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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
    /*
    第n-1次服务只能给a_n=1的
    而n-2次服务只能给a_n=1 a_n-1=1的
    因为要+2个数字等于2 所以只能那样
    所以咱们就是要看全由1组成的列有多少个
    */
    int n;
    cin >> n;
    vector<vi> a(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // vi cnt(n + 1);
    multiset<int> st;
    for (int i = 1; i <= n; i++) {
        int now = 0;
        for (int j = n; j >= 1; j--) {
            if (a[i][j] != 1)
                break;
            now++;
        }
        // cnt[now]++;
        st.insert(now);
    }
    for (int i = 1; i < n; i++) {
        if (*st.rbegin() < i) {
            cout << i << '\n';
            return;
        }
        st.erase(st.lower_bound(i));
    }
    cout << n << '\n';
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
        solve();
    return 0;
}