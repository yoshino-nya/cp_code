#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c >= a && d >= b)
    {
        int x = a, y = b;
        if (x > y)
            swap(x, y);
        if (y > (x + 1) * 2)
        {
            cout << "NO\n";
            return;
        }
        x = c - a, y = d - b;
        if (x > y)
            swap(x, y);

        if (y > (x + 1) * 2)
        {
            cout << "No\n";
            return;
        }
        // x = c, y = d;
        // if (x > y)
        //     swap(x, y);

        // if (y > (x + 1) * 2)
        // {
        //     cerr << x << " " << y << '\n';
        //     cout << "nO\n";
        //     return;
        // }
        cout << "YES\n";
    }
    else
        cout << "no\n";
    //RRKRRKRR
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}