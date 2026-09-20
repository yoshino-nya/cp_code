#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    multiset<int> st;
    vector<int> a(n);
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
        if(st.size() > m)
            st.erase(st.find(a[i - m]));
        if(st.size() == m && *st.rbegin() - *st.begin() <= c && (ok = true))
            cout << i - m + 1 + 1 << '\n';
    }
    if(!ok) cout << "NONE\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}