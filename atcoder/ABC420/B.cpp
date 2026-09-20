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

void ChatGptDeepSeek() // Date: 2025-08-24
{                      // Time: 20:03:08 
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> sc(n);
    for(int i = 0; i < m; i++){
        int x = 0, y = 0;
        for(int j = 0; j < n; j++){
            if(s[j][i] == '0') x++;
            else y++;
        }
        if(!x || !y){
            for(int j = 0; j < n; j++)
                sc[j]++;
            continue;
        }
        if(x < y){
            for(int j = 0; j < n; j++){
                if(s[j][i] == '0') sc[j]++;
            }
        }else{
            for(int j = 0; j < n; j++){
                if(s[j][i] == '1') sc[j]++;
            }
        }
    }
    int mx = *max_element(all(sc));
    for(int i = 0; i < n; i++)
        if(sc[i] == mx) cout << i + 1 << " ";
    cout << '\n';
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