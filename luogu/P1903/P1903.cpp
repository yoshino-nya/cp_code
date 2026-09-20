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
    int l, r, t, idx;
};
node Q[133333];
int cnt[int(1e6)+1];

void ChatGptDeepSeek() // Date: 2025-04-26
{                      // Time: 01:16:57 
    int n, m;
    cin >> n >> m;
    vi c(n + 1), pos(n + 1);
    int siz = pow(n, 0.667);
    for(int i = 1; i <= n; i++)
        cin >> c[i], pos[i] = i / siz;
    vector<pii> upd;
    int tot = 0;
    for(int i = 0, cnt = 0; i < m; i++){
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'R') upd.push_back({x, y}), cnt++;
        else Q[tot++] = {x, y, cnt, tot-1};
    }
    if(!tot) return;
    sort(Q, Q + tot, [&](node x, node y){
        if(pos[x.l] == pos[y.l]){
            if(pos[x.r] == pos[y.r]) return x.t < y.t;
            return pos[x.r] < pos[y.r];
        }
        return pos[x.l] < pos[y.l];
    });
    vi ans(tot), color(sz(upd));
    int L = 1, R = 0, T = 0, res = 0;
    auto add = [&](int i){
        cnt[c[i]]++;
        if(cnt[c[i]] == 1) res++;
    };
    auto sub = [&](int i){
        cnt[c[i]]--;
        if(cnt[c[i]] == 0) res--;
    };
    auto change = [&](int t){
        auto [P, C] = upd[t];
        color[t] = c[P];
        if(P >= L && P <= R){
            cnt[c[P]]--;
            if(cnt[c[P]] == 0) res--;
            cnt[C]++;
            if(cnt[C] == 1) res++;
        }
        c[P] = C;
    };
    auto recover = [&](int t){
        auto [P, C] = upd[t];
        c[P] = color[t];
        if(P >= L && P <= R){
            cnt[C]--;
            if(cnt[C] == 0) res--;
            cnt[c[P]]++;
            if(cnt[c[P]] == 1) res++;
        }
    };
    for(int i = 0; i < tot; i++){
        auto [l, r, t, idx] = Q[i];
        while(L > l) add(--L);
        while(R < r) add(++R);
        while(L < l) sub(L++);
        while(R > r) sub(R--);
        while(T < t) change(T++);
        while(T > t) recover(--T);
        ans[idx] = res;
    }
    for(int i = 0; i < tot; i++)
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