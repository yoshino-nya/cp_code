#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H + 1, vector<int> (W + 1));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> A[i][j];
        }
    }
    vector<int> P(H + W);
    for(int i = 1; i <= H + W - 1; i++)
        cin >> P[i];
    auto check = [&](long long x){
        vector<vector<long long>> dp(H + 1, vector<long long> (W + 1, -1));
        dp[1][1] = x;
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                if(i > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j > 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(dp[i][j] == -1) continue;
                dp[i][j] += A[i][j] - P[i + j - 1];
            }
        }
        return dp[H][W] >= 0;
    };
    long long lo = -1, hi = 200000000000001LL;
    while(lo < hi - 1){
        long long mid = (lo + hi) >> 1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}