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

ll f[555][555];

void ChatGptDeepSeek() // Date: 2025-07-26
{                      // Time: 20:37:18 
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = LNF;
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        f[a][b] = f[b][a] = min(f[a][b], c + 0ll);
    }
    int k, t;
    cin >> k >> t;
    vector<bool> vis(n + 1);
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        vis[x] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) continue;
        for(int j = i + 1; j <= n; j++){
            if(!vis[j]) continue;
            f[i][j] = f[j][i] = min(f[i][j], t + 0ll);
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 3){
            ll res = 0;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(f[i][j] != LNF)
                        res += f[i][j];
            cout << res << '\n';
            continue;
        }
        int x;
        if(op == 2){
            cin >> x;
            vis[x] = true;
            for(int i = 1; i <= n; i++){
                if(!vis[i]) continue;
                f[x][i] = f[i][x] = min(f[x][i], t + 0ll);
            }
        }else{
            int v, w;
            cin >> x >> v >> w;
            f[x][v] = f[v][x] = min(f[x][v], w + 0ll);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                f[i][x] = f[x][i] = min(f[i][x], f[i][j] + f[j][x]);
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][x] + f[x][j]);
    }
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