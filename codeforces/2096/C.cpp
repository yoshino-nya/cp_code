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

void ChatGptDeepSeek() // Date: 2025-04-20
{                      // Time: 00:09:04 
    int n;
    cin>>n;
    
    vector<vi>a(n+1,vi(n+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    vi A(n+1),B(n+1);
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    vector<vl> c(n+1,vl(2,LNF));
    c[1][0]=0;
    c[1][1]=A[1];
    for(int i=2;i<=n;i++){
        for(int x=0;x<2;x++){
            for(int y=0;y<2;y++){
                bool ok=true;
                for(int j=1;j<=n;j++){
                    if(a[i-1][j]+x==a[i][j]+y){ok=false;break;}
                }
                if(ok) cmin(c[i][y],c[i-1][x]+(y?A[i]:0));
            }
        }
    }
    ll ans=min(c[n][0],c[n][1]);
    if(ans==LNF){
        cout<<"-1\n";
        return;
    }
    c=vector<vl>(n+1,vl(2,LNF));
    c[1][1]=B[1],c[1][0]=0;
    for(int i=2;i<=n;i++){
        for(int x=0;x<2;x++){
            for(int y=0;y<2;y++){
                bool ok=true;
                for(int j=1;j<=n;j++){
                    if(a[j][i]+y==a[j][i-1]+x){ok=false;break;}
                }
                if(ok) cmin(c[i][y],c[i-1][x]+(y?B[i]:0));
            }
        }
    }
    if(min(c[n][1],c[n][0])==LNF){
        cout<<"-1\n";
        return;
    }
    ans+=min(c[n][1],c[n][0]);
    cout<<ans<<'\n';
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