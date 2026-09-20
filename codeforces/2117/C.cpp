#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int>lst, now;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    lst.insert(a[1]);
    int ans = 1;
    for(int i = 2; i <= n; i++){
        lst.erase(a[i]);
        now.insert(a[i]);
        if(lst.empty()){
            swap(lst, now);
            ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}