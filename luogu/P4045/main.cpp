#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 105;
int n, l;
int ch[N][26], fail[N], h[N], tot;
LL dp[2][N][1024];
bool ok[N][30][1024], vis[N][30][1024];
string res;
void insert(string s, int index)
{
    int u = 0;
    for(auto c : s){
        int x = c - 'a';
        if(!ch[u][x]) ch[u][x] = ++tot;
        u = ch[u][x];
    }
    h[u] |= 1 << index;
}
void build()
{
    queue<int> q;
    for(int u = 0; u < 26; ++u){
        if(ch[0][u])
            q.push(ch[0][u]);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        h[u] |= h[fail[u]];
        for(int v = 0; v < 26; ++v){
            if(ch[u][v]){
                fail[ch[u][v]] = ch[fail[u]][v];
                q.push(ch[u][v]);
            }else
                ch[u][v] = ch[fail[u]][v];
        }
    }
}
void check(int u, int len, int mask)
{
    if(vis[u][len][mask]) return;
    vis[u][len][mask] = true;
    if(len == l){
        if(mask == (1 << n) - 1) ok[u][len][mask] = true;
        return;
    }
    for(int x = 0; x < 26; ++x){
        int v = ch[u][x];
        check(v, len + 1, mask | h[v]);
        ok[u][len][mask] |= ok[v][len + 1][mask | h[v]];
    }
}
void output(int u, int len, int mask)
{
    if(!ok[u][len][mask]) return;
    if(len == l){
        cout << res << '\n';
        return;
    }
    for(int x = 0; x < 26; ++x){
        int v = ch[u][x];
        res.push_back('a' + x);
        output(v, len + 1, mask | h[v]);
        res.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> l >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        // insert(s[i], i);
    }
    ranges::sort(s);
    s.erase(unique(s.begin(), s.end()), s.end());
    n = s.size();
    for(int i = 0; i < n; ++i)
        insert(s[i], i);
    build();
    int now = 0;
    dp[now][0][0] = 1;
    for(int i = 0; i < l; ++i, now ^= 1){
        for(int u = 0; u <= tot; ++u)
            for(int mask = 0; mask < (1 << n); ++mask)
                dp[now ^ 1][u][mask] = 0;
        
        for(int u = 0; u <= tot; ++u){
            for(int mask = 0; mask < (1 << n); ++mask){
                LL num = dp[now][u][mask];
                if(!num) continue;
                for(int x = 0; x < 26; x++){
                    int v = ch[u][x];
                    dp[now ^ 1][v][mask | h[v]] += num;
                }
            }
        }
    }
    LL ans = 0;
    for(int u = 0; u <= tot; ++u)
        ans += dp[now][u][(1 << n) - 1];
    cout << ans << '\n';
    if(ans <= 42)
        check(0, 0, 0), output(0, 0, 0);
    return 0;
}