#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-16 16:49:23
int a[1010][1010], c[1010][1010], dp[1010][1010];
void solve(){
    /*
    0的数量等于 min(cnt_2, cnt_5)
    我们要同时保证两个数字数量小当然很难，看起来没办法做
    但是我们其实只需要求出2最少的路径和5最少的路径，
    一定有一个会是答案！
    这扯不扯，兄弟太性情了
    */
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            while(a[i][j] % 2 == 0 && a[i][j])
                c[i][j]++, a[i][j] /= 2;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += c[i][j];
            if(i + 1 <= n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(j + 1 <= n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    }
    auto calc = [&](){
        string res;
        int x = n, y = n;
        for(;;){
            if(x == 1 && y == 1) break;
            if(x > 1 && dp[x - 1][y] == dp[x][y] - c[x][y]) 
                x--, res.push_back('D');
            else y--, res.push_back('R');
        }
        reverse(res.begin(), res.end());
        return res;
    };
    auto path = [&](int i, int j){
        cout << "1\n";
        for(int x = 1; x < i; x++)
            cout << 'D';
        for(int x = 1; x < j; x++)
            cout << 'R';
        for(int x = i; x < n; x++)
            cout << 'D';
        for(int x = j; x < n; x++)
            cout << 'R';
        cout << "\n";
    };
    int ans1 = dp[n][n]; string s1 = calc();
    // cerr << ans1 << "\n";
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c[i][j] = 0;

            while(a[i][j] % 5 == 0 && a[i][j])
                c[i][j]++, a[i][j] /= 5;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += c[i][j];
            if(i + 1 <= n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(j + 1 <= n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    }
    int ans2 = dp[n][n]; string s2 = calc();
    if(min(ans1, ans2) > 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(!a[i][j]){
                    path(i, j);
                    return;
                }
            }
        }
    }
    cout << min(ans1, ans2) << "\n";
    cout << (ans1 <= ans2 ? s1 : s2) << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}