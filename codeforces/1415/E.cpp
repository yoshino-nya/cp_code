#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    sort(c.begin() + 1, c.end(), greater<int> ());
    priority_queue<LL> pq;
    for(int i = 1; i <= k + 1; i++) pq.push(0);
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        LL mx = pq.top(); pq.pop();
        ans += mx; pq.push(mx + c[i]);
    }
    cout << ans << '\n';
    return 0;
}