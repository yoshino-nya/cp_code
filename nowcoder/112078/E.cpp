#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;
    if(sum & 1){
        cout << "-1\n";
    }else{
        set<int> st;
        for(int i = 1; i <= n; i++)
            st.insert(i);
        sum /= 2;
        while(sum){
            auto it = *prev(st.upper_bound(sum));
            sum -= it;
            cout << it << " ";
            st.erase(it);
        }
        for(auto x : st)
            cout << x << " ";
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}