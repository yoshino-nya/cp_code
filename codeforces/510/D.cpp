#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first;
    for(int i = 0; i < n; i++)
        cin >> vec[i].second;
    set<int> st;
    map<int, int> mp;
    for(auto [l, c] : vec){
        if(!mp.contains(l)) mp[l] = c;
        else mp[l] = min(mp[l], c);
        vector<int> tmp{l};
        for(auto x : st){
            int g = gcd(x, l);
            // assert(mp[x]);
            if(!mp.contains(g)) mp[g] = mp[x] + c;
            else mp[g] = min(mp[g], mp[x] + c);
            tmp.push_back(g);
        }
        for(auto x : tmp)
            st.insert(x);
    }
    if(!mp.contains(1)) cout << "-1\n";
    else cout << mp[1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}