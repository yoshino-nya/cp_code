// Author: Zhangwuji
// Date: 2025-02-17
// Time: 23:52:08

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
    string s,c;
    cin>>s>>c;
    int n=sz(s);
    vi f(26);
    for(int i=0;i<n;i++)
        f[s[i]-'A']=i;
    if(s<c){
        cout<<s<<'\n';
        return;
    }
    vi suf(n);
    suf[n-1]=s[n-1]-'A';
    for(int i=n-2;i>=0;i--){
        suf[i]=min(suf[i+1],s[i]-'A');
    }
    //记录后缀的最小字母
    //否则s一定有一个字母比c大的，或者长度更长
    for(int i=0;i<min(sz(s),sz(c));i++){
        if(s[i]>c[i]){
            char ch=*min_element(s.begin()+i,s.end());
            swap(s[i],s[f[ch-'A']]);
            // cerr<<ch<<" "<<f[ch-'a']<<'\n';
            if(s<c)
                cout<<s<<'\n';
            else
                cout<<"---\n";
            return;
        }else{
            //等于的情况也可以交换
            if(suf[i]<s[i]-'A'){
                // cerr<<i<<" "<<suf[i]<<" "<<s[i]<<'\n';
                swap(s[i],s[f[suf[i]]]);
                cout<<s<<'\n';
                return;
            }
        }
    }
    cout<<"---\n";
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