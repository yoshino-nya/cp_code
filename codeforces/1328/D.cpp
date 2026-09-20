#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(count(a.begin(), a.end(), a[1]) == n){
        cout << "1\n";
        for(int i = 1; i <= n; i++)
            cout << "1 ";
        cout << "\n";
    }else{
        vector<array<int, 2>> dp(n + 1, {0, 0});
        dp[1][0] = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i - 1])
                dp[i][0] = dp[i][1] =  max(dp[i - 1][0], dp[i - 1][1]);
            for(int x = 0; x < 2; x++)
                dp[i][x] |= dp[i - 1][x ^ 1];
            // assert(dp[i][0] || dp[i][1]);
        }
        vector<int> ans(n + 1);
        ans[1] = 1;
        if(dp[n][1]){
            ans[n] = 2;
            for(int i = n - 1; i >= 1; i--){
                for(int x = 0; x < 2; x++){
                    if((a[i] == a[i + 1] || x + 1 != ans[i + 1]) && dp[i][x]){
                        ans[i] = x + 1;
                        // break;
                    }
                }
            }
        }else{
            for(int i = 1; i <= n; i++)
                ans[i] = i % 2 + 1;
            if(a[n] != a[1])
                ans[n] = 3;
        }
        cout << *max_element(ans.begin() + 1, ans.end()) << "\n";
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " \n" [i == n];
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}