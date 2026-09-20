// Author: Zhangwuji
// Date: 2025-01-27
// Time: 23:40:29

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 1会出现且只出现1次
    // 1在第几个出现
    // 说明第 n-i+2个数字是n (i>1)
    //
    // a[p]=n
    // p+1，n 1,p-1
    // 5 4 3 2 1 2
    // x x x x 6 x
    //[a5] [a6]
    int cnt = count(ALL(a),1);
    a.push_back(a[1]);
    for (int i = 1; i <= n; i++) {
        if(a[i+1]-a[i]>1){
            cout<<"NO\n";
            return;
        }
    }
    if (cnt != 1)
        cout << "NO\n";
    else
        cout << "YES\n";
    //减小是什么情况呢 增加是什么情况
    //我们只考虑最后一个数字
    //每次把最后一个数字移动到第一个
    //然后观察这个变化的值合不合法
    //比如原先的值 可能是 468..
    //如果他减小了，那么说明它是大于4的
    //如果值不变 也是可能的
    //但是增加的话 他就只能是比第一个数字小
    //不变的话 也可能是比他大 比他小
    //增加的话最多只能增加1
    //1 2 3 , 3
    //3 1 2

    //六百六十六 从错第178个数字 变成1577th
    //4 5 6 1 2 3
    //    123456
    //234561
    //345612
    //x.
    //比如说这一段已经是连续的了 那么再来一个数字之后
    //值是不能不变的

    //不变的条件是什么
    //来的是一个比它第一个大的数字 但又不能大太多。。。
    //6
    //46 ,2
    //546, 2
    //3546, 3
    //how...

    //好吧 只用判断 有1且只有一个 且增加不超过1
    //但是需要判断c[n]和c[1]
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
        solve();
    return 0;
}