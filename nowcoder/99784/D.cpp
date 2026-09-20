// Author: Zhangwuji
// Date: 2025-01-05
// Time: 19:12:23

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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
    string s;
    cin >> s;
    int n = sz(s);
    if (n & 1) {
        for (int i = 1; i <= n / 2 + 1; i++) {
            if (i & 1)
                cout << "11";
            else
                cout << "00";
        }
        return;
    }
    bool ok=false;
    string ans;
    auto add = [&](char x) {
        if (ans.size() && x == ans.back()) {
            if (x != '9')
                ans += string(2, x + 1);
            else {
                //... .. 11 99 99
                ans.pop_back();
                ans.pop_back();
                if (ans.empty()) {
                    n+=2;
                    while (sz(ans) < n) {
                        if (ans.size() && ans.back() != '0')
                            ans += "00";
                        else
                            ans += "11";
                    }
                    return true;
                }
                ans[sz(ans) - 1]++;
                ans[sz(ans) - 2]++;
                if (ans.size() >= 4) {
                    if (ans[sz(ans) - 3] == ans[sz(ans) - 1]){
                        ok=true;
                    }
                }
                return true;
            }
            return true;
        } else
            ans += string(2, x);
        return false;
    };
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            if (add(s[i]))
                break;
        } else if (s[i] < s[i + 1]) {
            // s[i]<[i+1]
            add(s[i] + 1);
            break;
        } else {
            add(s[i]);
            break;
        }
        if(ok) break;
    }
    auto check=[&](auto &&self)->void{
        if(ok){
            while(!ans.empty()&&ans.back()=='9'){
                ans.pop_back();
                ans.pop_back();
            }
            if(ans.empty()){
                n+=2;
                return;
            }
            ans[sz(ans)-1]++;
            ans[sz(ans)-2]++;
            if(sz(ans)>=4){
                if(ans[sz(ans)-1]==ans[sz(ans)-3])
                    self(self);
            }
        }
    };
    check(check);
    while (sz(ans) < n) {
        if (ans.size() && ans.back() != '0')
            ans += "00";
        else
            ans += "11";
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}