#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    string s; cin >> s;
    set<char> st;
    for(int i = 0; i * 2 < s.size() - 1; i++)
        st.insert(s[i]);
    cout << (st.size() > 1 ? "YES\n" : "NO\n");
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}