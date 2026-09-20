#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    if(s.find(string(k, '1')) != -1) cout << "NO\n";
    else{
        vector<int> ans(n);
        int x = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') ans[i] = x--;
        }
        for(int i = 0; i < n; i++)
            if(s[i] == '1') ans[i] = x--;
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
5 2

*/