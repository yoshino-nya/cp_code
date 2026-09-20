#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    // 101110
    // 011101
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a[2]{0, 0};
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == '1') {
            if(s[(i + 1) % (2 * n)] == '1') a[i & 1] += 1;
            else a[(i & 1) ^ 1] += 1;
        }
    }
    cout << a[1] << " " << a[0] << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}