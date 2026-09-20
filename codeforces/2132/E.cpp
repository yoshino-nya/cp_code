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

void ChatGptDeepSeek() // Date: 2025-08-22
{                      // Time: 00:02:14 
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    vector<ll> prea(n + 1), preb(m + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    sort(ALL(a), greater<>()), sort(ALL(b), greater<>());
    for(int i = 1; i <= n; i++)
        prea[i] = prea[i - 1] + a[i];
    for(int i = 1; i <= m; i++)
        preb[i] = preb[i - 1] + b[i];
    vector<pii> c;
    for(int i = 1; i <= n; i++)
        c.push_back({a[i], 1});
    for(int i = 1; i <= m; i++)
        c.push_back({b[i], 0});
    sort(all(c), greater<>());
    vector<ll> prec(n + m + 1), cnta(n + m + 1);
    for(int i = 1; i <= n + m; i++){
        prec[i] = prec[i - 1] + c[i - 1].first;
        cnta[i] = cnta[i - 1] + c[i - 1].second;
    }
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        /*
        看最大的 z 个有多少个是 a 里面的
        
        cnta <= x && z - cnta <= y， ok
        cnta <= x && z - cnta > y，那么取 b 的前y个，a的前 z - y个

        cnta > x && z - cnta <= y, a的前x个，b的前z-x个
        cnta > x && z - cnta > y, 不可能
        */
        // cerr << cnta[z] << " \n";
        if(cnta[z] <= x && z - cnta[z] <= y){
            cout << prec[z] << '\n';
            // cerr << "case1\n";
        }else if(cnta[z] <= x && z - cnta[z] > y){
            cout << preb[y] + prea[z - y] << '\n';
            // cerr << "case2\n";

        }else if(cnta[z] > x && z - cnta[z] <= y){
            cout << prea[x] + preb[z - x] << '\n';
            // cerr << "case3\n";
        }else{
            assert(0);
        }
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
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}