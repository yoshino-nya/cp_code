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

void ChatGptDeepSeek() // Date: 2025-07-23
{                      // Time: 21:53:09 
    int n, m;
    cin >> n >> m;
    /*
    bi 肯定只会选一个人的
    我们假设要选这个 bi 那么要把所有比这个 bi 大的 ai 给加上
    直接按bi 排序如何？
    小的 bi 在前面，
    这样单调队列就行
    */
    vector<array<int, 2>> vec(m);
    for(int i = 0; i < m; i++)
        cin >> vec[i][0] >> vec[i][1];
    ranges::sort(vec, [](array<int, 2> x, array<int, 2> y){
        return x[1] < y[1];
    });
    ll sum = 0, ans = 0;
    priority_queue<int, vi, greater<>> pq; 
    for(auto [a, b] : vec){
        while(pq.size() && pq.top() <= b){
            sum -= pq.top();
            pq.pop();
        }
        while(pq.size() >= n){
            sum -= pq.top();
            pq.pop();
        }
        cmax(ans, sum + a + 1LL * (n - 1 - sz(pq)) * b);
        sum += a;
        pq.push(a);
    }
    cout << ans << '\n';
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