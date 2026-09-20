#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200005;
vector<vector<int>> divisors;
array<int, N> cnt;
void solve()
{
    int n; cin >> n;
    vector<int> ans(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans[i] = ans[i - 1];
        for(auto d : divisors[a[i]]){
            cnt[d]++;
            if(cnt[d] < i) ans[i] = max(ans[i], cnt[d]);
        }
        for(auto d : divisors[a[i - 1]])
            if(cnt[d] < i) ans[i] = max(ans[i], cnt[d]);
        cout << ans[i] << " \n" [i == n];
    }
    for(int i = 1; i <= n; i++){
        for(auto d : divisors[a[i]]) cnt[d] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    divisors.assign(N, {});
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i)
            divisors[j].push_back(i);
    }
    int t; cin >> t; while(t--)
    {solve();} return 0;
}