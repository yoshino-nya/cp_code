#include<bits/stdc++.h>
using namespace std;

constexpr int M = int(5e5);
constexpr int inf = int(1e9);
int dp[M + 1];

void solve(){
    int m;
    cin >> m;
    cout << (dp[m] != inf ? dp[m] : -1) << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 1; i <= M; i++)
        dp[i] = inf;
    dp[1] = 1;
    for(int a = 1; a <= M; a++){
        for(int b = 1; b * (a + 2) <= M; b++)
            dp[(a + 2) * b] = min(dp[(a + 2) * b], dp[a] + dp[b]);
    }
    int t; cin >> t; while(t--)
    solve(); return 0;
}