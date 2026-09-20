#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long p, q;
    cin >> p >> q;
    if (p >= q || 3 * p < 2 * q)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*

*/