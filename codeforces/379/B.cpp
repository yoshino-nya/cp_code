// Date: 2025-03-06
// Time: 23:04:30

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    string s;
    for (int i = 1; i <= n; i++) {
        while (a[i]) {
            if (i == n)
                s += "LRP";
            else
                s += "RLP";
            a[i]--;
        }
        if (i != n)
            s += "R";
    }
    cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}