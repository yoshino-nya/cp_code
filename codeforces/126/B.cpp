// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1 &x, const T2 &y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1 &x, const T2 &y)
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

void ChatGptDeepSeek() // Date: 2025-04-16
{                      // Time: 10:04:50
    string s;
    cin >> s;
    int n = sz(s);
    if (n <= 2)
    {
        cout << "Just a legend\n";
        return;
    }
    auto get = [&](string t)
    {
        vi b(t.size());
        for (int i = 1; i < t.size(); i++)
        {
            int j = b[i - 1];
            while (j > 0 && t[i] != t[j])
                j = b[j - 1];
            b[i] = j;
            if (t[i] == t[j])
                b[i]++;
            // cerr<<b[i]<<" \n"[i+1==n];
        }
        return b;
    };
    vi b1 = get(s);
    for (int j = b1[n - 1]; j > 0; j = b1[j - 1])
    {
        string x=s.substr(0,j);
        vi b2=get(x);
        int idx=0;
        for(int i=1;i+1<n;i++){
            while(idx>0&&x[idx]!=s[i])
                idx=b2[idx-1];
            if(x[idx]==s[i])
                idx++;
            if(idx==j){
                cout<<x<<"\n";
                return;
            }
        }
    }
    cout << "Just a legend\n";
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