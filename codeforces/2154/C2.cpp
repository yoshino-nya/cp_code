#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int N = 400500;
vector<int> primes;
int minp[N + 1], cnt1[N + 1];
vector<vector<int>> res;
vector<int> get(int k){
    if(!res[k].empty() || k == 1){
        return res[k];
    }
    int n = k;
    while(k != 1){
        int p = minp[k];
        res[n].push_back(p);
        while(k % p == 0)
            k /= p;
    }
    return res[n];
}
void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> vec(n + 1);
    for(int i = 1; i <= n; i++) cin >> vec[i].first;
    for(int i = 1; i <= n; i++) cin >> vec[i].second;
    sort(vec.begin() + 1, vec.end(), [](pair<int, int> &x, pair<int, int> &y){
        return x.second < y.second;
    });
    LL ans = 1e18;
    vector<int> divisors;
    for(int i = 1; i <= n; i++){
        for(auto p : get(vec[i].first)){
            if(cnt1[p]) ans = 0;
            cnt1[p]++;
            divisors.push_back(p);
        }
    }
    ans = min(ans, 0LL + vec[1].second + vec[2].second);
    for(int i = 1; i <= n && ans; i++){
        if(i == 1){
            for(auto d : divisors){
                if(cnt1[d] == 1 && vec[i].first % d == 0) continue;
                ans = min(ans, 1LL * (d - vec[i].first % d) * vec[i].second);
            }
        }else{
            for(auto p : get(vec[i].first + 1)){
                if(cnt1[p])
                    ans = min(ans, 0LL + vec[i].second);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(auto p : get(vec[i].first))
            cnt1[p] = 0;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(!minp[i]){
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes){
            if(i * p > N) break;
            minp[i * p] = p;
            if(i % p == 0) break;
        }
    }
    res.assign(N + 1, {});
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}