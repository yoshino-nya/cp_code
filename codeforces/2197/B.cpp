#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> p(n + 1), q(n + 1);
    for(int i = 1; i <= n; i++) p[a[i]] = i;
    for(int i = 1; i <= n; i++) q[i] = p[b[i]];
    if(is_sorted(q.begin() + 1, q.end()))
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    
}
/*

7
1 3 2 7 5 4 6
6 6 6 6 6 5 5
*/