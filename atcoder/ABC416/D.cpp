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

void ChatGptDeepSeek() // Date: 2025-07-26
{                      // Time: 20:28:02 
    int n, mod;
    cin >> n >> mod;
    vi A(n), B(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> B[i];
    multiset<int> st(all(A));
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += A[i] + B[i];
    ranges::sort(B, greater<>());
    for(int i = 0; i < n; i++){
        auto it = st.lower_bound(mod - B[i]);
        if(it == st.end()) break;
        ans -= mod;
        st.erase(it);
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