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

constexpr int N = int(5e4)+5;
struct node{
    int l, r, idx;
};
node Q[N];
void ChatGptDeepSeek() // Date: 2025-04-26
{                      // Time: 00:48:12 
    /*
    洛谷P1494
    询问区间的抽到两个相同数字的概率
    */
    int n, m;
    cin >> n >> m;
    int siz = sqrt(n);
    vi c(n + 1), pos(n + 1), cnt(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> c[i], pos[i] = i / siz;
    for(int i = 0; i < m; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }
    sort(Q, Q + m, [&](node x, node y){
        return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    });
    ll res = 0;
    auto add = [&](int i){
        res -= (ll)cnt[c[i]] * (cnt[c[i]] - 1) / 2;
        cnt[c[i]]++;
        res += (ll)cnt[c[i]] * (cnt[c[i]] - 1) / 2;
    };
    auto sub = [&](int i){
        res -= (ll)cnt[c[i]] * (cnt[c[i]] - 1) / 2;
        cnt[c[i]]--;
        res += (ll)cnt[c[i]] * (cnt[c[i]] - 1) / 2;
    };
    int L = 1, R = 0;
    vector<string> ans(m);
    for(int i = 0; i < m; i++){
        auto [l, r, idx] = Q[i];
        while(L > l) add(--L);
        while(R < r) add(++R);
        while(L < l) sub(L++);
        while(R > r) sub(R--);
        ll X = (ll)(R - L + 1) * (R - L) / 2;
        ll g = __gcd(X, res);
        // cout << res / g << "/" << X / g << '\n';
        if(g == 0) ans[idx] = "0/1";
        else
            ans[idx] = format("{}/{}",res/g,X/g);
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