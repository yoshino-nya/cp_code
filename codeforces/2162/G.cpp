#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    if(n <= 2) cout << "-1\n";
    else if(n == 3) cout << "1 3\n2 3\n";
    else if(n == 4) cout << "1 2\n3 1\n4 1\n";
    else{
        cout << "1 2\n2 3\n3 4\n";
        cout << "1 " << n << "\n";
        for(int i = 5; i < n; i++)
            cout << "2 " << i << '\n'; 
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}