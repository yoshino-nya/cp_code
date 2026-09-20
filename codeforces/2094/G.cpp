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
// Time: 11:19:19
void ChatGptDeepSeek()
{
    int q;
    cin >> q;
    ll ans = 0, sum = 0, m = 0;
    deque<int> dq;
    int f = 0;
    while(q--){
        int s;
        cin >> s;
        if(s == 3){
            int k; cin >> k;
            m++;
            sum += k, ans += m * k;
            if(f) dq.push_front(k);
            else dq.push_back(k);
        }else if(s == 2){
            ans = sum * (m + 1) - ans;
            f ^= 1;
        }else{
            ans += sum - (f ? dq.front() : dq.back()) * m;
            // 哦哦，操作1的话，我们因为把最后一个弄到前面去了，所以需要操作一下
            if(f){
                dq.push_back(dq.front());
                dq.pop_front();
            }else{
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        cout << ans << '\n';
    }
}
/*
用deque就行，操作1只需要知道末尾元素是谁
操作2的话 就反转一下头就行
操作3就push一下就行
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