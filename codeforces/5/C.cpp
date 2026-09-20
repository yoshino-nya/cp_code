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

void ChatGptDeepSeek() // Date: 2025-04-21
{                      // Time: 17:32:33 
    string s;
    cin>>s;
    int now=0,cnt=1,len=0,cur_len=0;
    for(auto x:s){
        cur_len++;
        if(x=='(') now++;
        else now--;
        if(now<0){
            now=0;
            cur_len=0;
        }else if(now==0){
            if(cur_len>len){
                cnt=1;
                len=cur_len;
            }else if(cur_len==len)
                cnt++;
        }
    }
    int ans_len=len,ans_cnt=cnt;
    now=0,cnt=1,len=0,cur_len=0;
    reverse(all(s));
    for(auto x:s){
        cur_len++;
        if(x=='(') now++;
        else now--;
        if(now>0){
            now=0;
            cur_len=0;
        }else if(now==0){
            if(cur_len>len){
                cnt=1;
                len=cur_len;
            }else if(cur_len==len)
                cnt++;
        }
    }
    if(len>ans_len) cout<<len<<" "<<cnt<<'\n';
    else if(len==ans_len&&cnt>ans_cnt) cout<<len<<" "<<cnt<<'\n';
    else cout<<ans_len<<" "<<ans_cnt<<'\n';
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