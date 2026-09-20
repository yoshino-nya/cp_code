// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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

struct node {
    int l, r, idx;
};
void ChatGptDeepSeek() // Date: 2025-04-25
{ // Time: 15:33:26
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), c(k + 1), ans(m), pos(n + 1);
    int siz = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pos[i] = i / siz;
    vector<node> Q(m);
    for (int i = 0; i < m; i++)
        cin >> Q[i].l >> Q[i].r, Q[i].idx = i;
    sort(all(Q), [&](node x, node y) {
        return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    });
    int L = 1, R = 0;
    ll res = 0;
    auto add = [&](int i) {
        assert(i > 0 && i <= n);
        res -= (ll)c[a[i]] * c[a[i]];
        c[a[i]]++;
        res += (ll)c[a[i]] * c[a[i]];
    };
    auto sub = [&](int i) {
        assert(i > 0 && i <= n);
        res -= (ll)c[a[i]] * c[a[i]];
        c[a[i]]--;
        res += (ll)c[a[i]] * c[a[i]];
    };
    
    for (int i = 0; i < m; i++) {
        auto [l, r, idx] = Q[i];
        while(L > l) add(--L);
        while(R < r) add(++R);
        while(L < l) sub(L++);
        while(R > r) sub(R--);
        // cerr << L << " " << R << '\n';
        ans[idx] = res;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}