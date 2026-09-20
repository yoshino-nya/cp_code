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

// Date: 2025-05-18
// Time: 02:50:01
void ChatGptDeepSeek()
{
    int n, m, l;
    cin >> n >> m >> l;
    /*
    看总和是奇数还是偶数
    然后最小的奇数找出来
    这样能知道最大的 奇/偶
    然后算出到每个点的最短距离
    若是奇数，则看最大的奇数是否大于这个距离
    不行的话，就看周围连的点，有没有也是奇数距离的，若有，则自己可以是偶数距离
    且值为周围是奇数距离的最小值
    */
    int sum = 0, miodd = INF;
    for(int i = 1; i <= l; i++){
        int x;
        cin >> x;
        sum += x;
        if(x & 1)
            cmin(miodd, x);
    }
    int maxE = 0, maxO = 0;
    if(sum & 1){
        maxO = sum, maxE = sum - miodd;
    }else{
        maxE = sum;
        if(miodd != INF)
            maxO = sum - miodd;
    }
    vc<vi> g(n + 1, vi());
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> dis(n + 1, {INF, INF});
    priority_queue<array<int, 3>, vc<array<int, 3>>, greater<>> pq;
    pq.push({0, 1, 0});
    dis[1][0] = 0;    
    while(!pq.empty()){
        auto [dist, u, s] = pq.top();
        pq.pop();
        if(dist > dis[u][s]) continue;
        for(auto v : g[u]){
            if(dis[v][s ^ 1] > dist + 1){
                dis[v][s ^ 1] = dist + 1;
                pq.push({dis[v][s ^ 1], v, s ^ 1});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if((dis[i][0] != INF && dis[i][0] <= maxE) || (dis[i][1] != INF && dis[i][1] <= maxO))
            cout << 1;
        else
            cout << 0;
    }
       
    cout << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    // freopen("1.in", "r", stdin);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}