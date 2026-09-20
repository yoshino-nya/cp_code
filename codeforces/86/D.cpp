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

constexpr int N = int(1e6)+5;
int cnt[N];
struct node{
    int l, r, idx;
};
node Q[N];
void ChatGptDeepSeek() // Date: 2025-04-25
{                      // Time: 21:27:09 
    int n, q;
    cin >> n >> q;
    vi a(n + 1), pos(n + 1);
    vl ans(q + 1);
    int siz = sqrt(n);
    for(int i = 1; i <= n; i++)
        cin >> a[i], pos[i] = i / siz;
    // vector<node>Q(q);
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }
    sort(Q, Q + q, [&](node x, node y){
        return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    });
    // sort(all(Q), [&](node x, node y){
    //     return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    // });
    ll res = 0;
    auto add = [&](int i){
        res -= (ll)cnt[a[i]] * cnt[a[i]] * a[i];
        cnt[a[i]]++;
        res += (ll)cnt[a[i]] * cnt[a[i]] * a[i];
    };
    auto sub = [&](int i){
        res -= (ll)cnt[a[i]] * cnt[a[i]] * a[i];
        cnt[a[i]]--;
        res += (ll)cnt[a[i]] * cnt[a[i]] * a[i];
    };
    int L = 1, R = 0;
    for(int i = 0; i < q; i++){
        auto [l, r, idx] = Q[i];
        while(L > l) add(--L);
        while(R < r) add(++R);
        while(L < l) sub(L++);
        while(R > r) sub(R--);
        ans[idx] = res;
    }
    for(int i = 0; i < q; i++)
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