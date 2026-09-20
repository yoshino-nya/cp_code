#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<LL> a(n + 1);
    LL sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; sum += a[i];
    }
    if(sum % n){
        cout << "-1\n";
        return;
    }
    sum /= n;
    vector<array<int, 3>> ans;
    
    auto op = [&](int i, int j, int x){
        a[i] -= i * x, a[j] += i * x;
        ans.push_back({i, j, x});
    };
    for(int i = 2; i <= n; i++){
        if(a[i] % i){
            op(1, i, i - (a[i] % i));
        }
        op(i, 1, a[i] / i);
    }
    for(int i = 2; i <= n; i++)
        op(1, i, sum);
    cout << ans.size() << '\n';
    for(auto [i, j, x] : ans)
        cout << i << " " << j << " " << x << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}