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

// Date: 2025-05-30
// Time: 08:25:18
struct Fenwick{
    vi b;
    Fenwick(int n){
        b.resize(n);
    }
    int lowbit(int x){return (x) & (-x);}
    void add(int i){
        while(i < b.size()){
            b[i] += 1;
            i += lowbit(i);
        }
    }
    int query(int i){
        int res = 0;
        while(i){
            res += b[i];
            i -= lowbit(i);
        }
        return res;
    }
};
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    auto calc = [&](vi vec){
        Fenwick tr(n + 1);
        int res = 0;
        for(int i = sz(vec) - 1; i >= 0; i--){
            res += tr.query(vec[i]) % 2;
            tr.add(vec[i]);
        }
        return res;
    };
    vi p1, p2;
    for(int i = 1; i <= n; i++){
        if(i & 1) p1.push_back(a[i]);
        else p2.push_back(a[i]);
    }
    int r1 = calc(p1), r2 = calc(p2);
    ranges::sort(p1), ranges::sort(p2);
    for(int i = 1, j = 0, k = 0; i <= n; i++){
        if(i & 1) a[i] = p1[j++];
        else a[i] = p2[k++];
    }
    if(r1 % 2 != r2 % 2) swap(a[n - 2], a[n]);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}
/*
3 4 2 1
2 1 3 4

3 1 5 4 2
3 4 2 1 5
2 1 3 4 5

i + 1, i + 2, i + 3, i + 4, i + 5
i + 1, i + 4, i + 5, i + 2, i + 3,
i + 5, i + 2, i + 1, i + 4, i + 3,
*/
int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}