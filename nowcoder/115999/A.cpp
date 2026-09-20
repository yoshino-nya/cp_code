#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k;
int vis[101][2];
bool dfs(int N, int K)
{
    if(vis[N][K] != -1)
        return vis[N][K];
    if(N + k >= n)
        return vis[N][K] = K;
    int x = 0, y = 0;
    for(int i = 1; i <= k && i + N <= n; i++){
        if(dfs(N + i, K ^ 1)) x++;
        else y++;
    }
    int res = 0;
    // cerr << N << "  " << K << " " << x << " " << y << "\n";
    if(K){
        if(x) res = 1;
        // else return false;
    }

    if(!y) res = 1;
    // return false;
    vis[N][K] = res;
    return res;
}
void solve()
{
    memset(vis, -1, sizeof vis);
    cin >> n >> k;
    if(dfs(0, 1)) cout << "Blueberry\n";
    else cout << "Strawberry\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}