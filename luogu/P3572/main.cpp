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

// Date: 2025-05-29
// Time: 00:26:23
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi d(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        // 要么会去区间的最大值
        // 要么会去比自己小的最大的值吧
        // 去大的是不是不如去小的？
        // 小的没有了再走大的
        // 只用记 最小的cost 以及最大的 d
        if(n == 1){
            cout << "0\n";
            continue;
        }
        auto cmp = [](array<int, 3> x, array<int, 3> y){
            return x[0] == y[0] ? (x[1] < y[1]) : (x[0] > y[0]);
        };
        priority_queue<array<int, 3> , vc<array<int, 3>>, decltype(cmp)> pq;
        pq.push({0, d[1], 1});
        for(int i = 2; i <= n; i++){
            while(!pq.empty() && pq.top()[2] < i - k)
                pq.pop();
            auto [cost, height, j] = pq.top();
            if(height <= d[i])
                pq.push({cost + 1, d[i], i});
            else
                pq.push({cost, d[i], i});
            if(i == n)
                cout << (height <= d[i] ? cost + 1 : cost) << '\n';
        }
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}