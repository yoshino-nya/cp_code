#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> dp(32);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int mx = 0;
        for(int j = 0; j < 31; j++)
            if(x >> j & 1) mx = max(mx, dp[j]);
        for(int j = 0; j < 31; j++)
            if(x >> j & 1) dp[j] = mx + 1;
    }
    cout << ranges::max(dp) << '\n';
    return 0;
}