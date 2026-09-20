#include <bits/stdc++.h>
using namespace std;

struct node{
    int val, pos;  
};
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    auto cmp = [](node x, node y){
        return x.pos > y.pos;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    vector<int> lst(n + 1);
    for(int i = 1; i <= n; i++)
        lst[a[i]] = i;
    for(int i = 1; i <= n; i++)
        pq.push({i, lst[i]});
    while(k--){
        cout << pq.top().val << " ";
        pq.pop();
    }
    cout << "\n";
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}