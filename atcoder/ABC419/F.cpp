// ABC419: F
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
int ch[105][26], fail[105], id[105], rt = 1, tot = rt;
int dp[2][105][1024];

void add(int &x, int y)
{
    // x += y;
    // if(x >= mod) x -= mod;
    // if(x < 0) x += mod;
    x += y-mod;x += x>>31&mod;
}
void insert(string s, int index)
{
    int u = rt;
    for(auto c : s){
        int x = c - 'a';
        if(!ch[u][x]) ch[u][x] = ++tot;
        u = ch[u][x];
    }
    id[u] |= 1 << index;
}
void build()
{
    queue<int> q;
    for(int i = 0; i < 26; ++i){
        if(ch[rt][i]){
            fail[ch[rt][i]] = rt;
            q.push(ch[rt][i]); 
        }else ch[rt][i] = rt;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        id[u] |= id[fail[u]];
        for(int v = 0; v < 26; ++v){
            if(ch[u][v]){
                fail[ch[u][v]] = ch[fail[u]][v];
                q.push(ch[u][v]);
            }else
                ch[u][v] = ch[fail[u]][v];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, l; cin >> n >> l;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        insert(s, i);
    }
    build();
    int now = 0;
    dp[now][rt][0] = 1;
    for(int i = 0; i < l; ++i){
        for(int u = 1; u <= tot; ++u)
            for(int mask = 0; mask < (1 << n); ++mask)
                dp[now ^ 1][u][mask] = 0;
        for(int u = 1; u <= tot; ++u){
            for(int mask = 0; mask < (1 << n); ++mask){
                int num = dp[now][u][mask];
                if(!num) continue;
                for(int x = 0; x < 26; ++x){
                    int v = ch[u][x];
                    // dp[now ^ 1][v][mask | id[v]] = (dp[now ^ 1][v][mask | id[v]] + num) % mod;
                    add(dp[now ^ 1][v][mask | id[v]], num);
                }
            }
        }
        now ^= 1;
    }
    int ans = 0;
    for(int u = 1; u <= tot; ++u)
        add(ans, dp[now][u][(1 << n) - 1]);
    cout << ans << '\n';
    return 0;
}