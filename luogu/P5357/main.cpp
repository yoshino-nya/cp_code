#include<bits/stdc++.h>
using namespace std;

constexpr int N = int(2e5) + 5;
int trie[N][26], fail[N], point[N], rt = 1, tot = rt;
int head[N], nxt[N], to[N], sum[N], idx = 1;

void insert(string s, int index)
{
    int u = rt;
    for(auto c : s){
        int x = c - 'a';
        if(!trie[u][x]) trie[u][x] = ++tot;
        u = trie[u][x];
    }
    point[index] = u;
}
void build()
{
    queue<int> q;
    fail[rt] = rt;
    for(int i = 0; i < 26; i++){
        if(trie[rt][i]){
            fail[trie[rt][i]] = rt;
            q.push(trie[rt][i]);
        }
        else trie[rt][i] = rt;
    }
    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(int v = 0; v < 26; v++){
            if(trie[u][v])
                fail[trie[u][v]] = trie[fail[u]][v], q.push(trie[u][v]);
            else
                trie[u][v] = trie[fail[u]][v];
        }
    }
}
void addEdge(int u, int v)
{
    to[idx] = v;
    nxt[idx] = head[u];
    head[u] = idx;
    idx++;
}
void dfs(int u)
{
    for(int i = head[u]; i; i = nxt[i]){
        dfs(to[i]);
        sum[u] += sum[to[i]];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        insert(s, i);
    }
    build();
    for(int i = 2; i <= tot; i++){
        addEdge(fail[i], i);
    }
    string s; cin >> s;
    int u = rt;
    for(auto c : s){
        int x = c - 'a';
        u = trie[u][x];
        sum[u]++;
    }
    dfs(rt);
    for(int i = 1; i <= n; i++)
        cout << sum[point[i]] << "\n";
    return 0;
}