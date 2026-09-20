#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 998244353;
int mx[5050][13];
LL dp[5050][5050][2];
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 1; i + (1 << j) <= n + 1; i++)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    auto query = [&](int l, int r){
        if(l > r) return 0;
        int k = __lg(r - l + 1);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    };
    vector<int> li;
    {
        vector<int> l, r;
        for(int i = 1; i <= n; i++)
            if(l.empty() || a[i] > a[l.back()])
                l.push_back(i);
        for(int i = n; i >= 1; i--)
            if(r.empty() || a[i] > a[r.back()])
                r.push_back(i);
        li = l;
        int lst = 1e9;
        for(auto id : r){
            // cerr << id << " \n";
            if(l.size() && a[id] == a[l.back()]){
                // cerr << id << " " << l.back() << " " << lst << " \n";
                if(query(l.back() + 1, id - 1) > lst)
                    li.push_back(id);
                l.pop_back();
            }
            else{
                // cerr << id << "\n";
                li.push_back(id);
                // cerr << "sz : " << li.size() << "\n";
            }
            lst = a[id];
            // cerr << lst << ""
        }
        sort(li.begin(), li.end());
        for(auto &i : li)
            i = a[i];
        // cout << li.size() << "\n";
        // for(auto x : li)
        //     cout << x << " ";
        // cout << "\n";
    }
    dp[0][0][1] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < li.size(); j++){
            if(a[i] == li[j]){
                dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][1]) % mod;
                if(j) dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][0]) % mod;
            }else{
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            }
        }
        ans = (ans + dp[i][li.size()][1]) % mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}