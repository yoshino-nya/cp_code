#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << count(s.begin(), s.end(), '1') << '\n';
    for(int i = 0; i < n; i++){
        if(s[i] == '1')
            cout << i + 1 << " ";
    }
    cout << "\n";
}
int main()
{
    // freopen("1.in", "r", stdin);
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}