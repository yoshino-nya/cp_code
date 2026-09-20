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
    for(int m = 2; m <= M; m++){
        for(int p = 1; p * p <= m; p++){
            if(m % p) continue;
            if(p > 2) dp[m] = min(dp[m], dp[m / p] + dp[p - 2]);
            if(m / p > 2) dp[m] = min(dp[m], dp[p] + dp[m / p - 2]);
        }
    }
    int t; cin >> t; while(t--)
    solve(); return 0;
}