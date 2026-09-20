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

struct node{
    int l, r, idx;
};
node Q[100001];
int cnt[200002];
void ChatGptDeepSeek() // Date: 2025-04-26
{                      // Time: 20:37:22 
    int n, m, k;
    cin >> n >> m >> k;
    int siz = sqrt(n);
    vector<int> a(n + 1), pos(n + 1), pre(n + 1);
    vl ans(m);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        pos[i] = i / siz;
    }
    for(int i = 0; i < m; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }
    sort(Q, Q + m, [&](node x, node y){
        return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    });
    ll res = 0;
    auto add = [&](int i){
        res += cnt[pre[i] ^ k];
        cnt[pre[i]]++;
    };
    auto sub = [&](int i){
        cnt[pre[i]]--;
        res -= cnt[pre[i] ^ k];
    };
    cnt[0] = 1;
    int L = 0, R = 0;
    for(int i = 0; i < m; i++){
        auto [l, r, idx] = Q[i];
        --l;
        while(L > l) add(--L);
        while(R < r) add(++R);
        while(L < l) sub(L++);
        while(R > r) sub(R--);
        ans[idx] = res;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
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