// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

constexpr int N = int(1e5) + 5;
struct tree{
    int l, r, cnt;
    ll ans;
    tree(int v = 0){
        l = r = cnt = ans = v;
    }
};
tree tr[N * 50];
#define mi ((l + r) >> 1)
#define lson tr[p].l
#define rson tr[p].r
int cnt = 0, rt[N];

void push_up(int p)
{
    tr[p].cnt = max(tr[lson].cnt, tr[rson].cnt);
    if(tr[lson].cnt > tr[rson].cnt)
        tr[p].ans = tr[lson].ans;
    else if(tr[lson].cnt < tr[rson].cnt)
        tr[p].ans = tr[rson].ans;
    else
        tr[p].ans = tr[lson].ans + tr[rson].ans;
}
void update(int &now, int l, int r, int pos, int v)
{
    if(!now) now = ++cnt;
    if(l == r){
        tr[now].cnt += v;
        tr[now].ans = l;
        return;
    }
    if(pos <= mi) update(tr[now].l, l, mi, pos, v);
    else update(tr[now].r, mi + 1, r, pos, v);
    push_up(now);
}
int merge(int a, int b, int l, int r)
{
    if(!a) return b;
    if(!b) return a;
    if(l == r){
        tr[a].cnt += tr[b].cnt;
        tr[a].ans = l;
        return a;
    }
    tr[a].l = merge(tr[a].l, tr[b].l, l, mi);
    tr[a].r = merge(tr[a].r, tr[b].r, mi + 1, r);
    push_up(a);
    return a;
}
void ChatGptDeepSeek() // Date: 2025-04-29
{                      // Time: 23:52:50 
    int n;
    cin >> n;
    cnt = n;
    vi c(n + 1);
    vl ans(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        rt[i] = i;
    }
    vector<vi> g(n + 1, vi());
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int u, int pre) -> void{
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            rt[u] = merge(rt[u], rt[v], 1, 100000);
        }
        update(rt[u], 1, 100000, c[u], 1);
        ans[u] = tr[rt[u]].ans;
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#else
    int START = clock();
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
#ifdef YUANSHEN
    cerr << "Run Time: " << (clock() - START)/1000.0 << "ms\n";
#endif
    return 0;
}