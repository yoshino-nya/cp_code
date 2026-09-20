#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    /* 也就是说匹配的得恰好是 k 对
     * 也就是说剩下的东西，n - 2k 个数字，必须是一半 1， 一半 0
     */
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), '0');
    int y = n - x;
    int z = (n - 2 * k) / 2;
    x -= z, y -= z;
    if (x >= 0 && y >= 0 && x % 2 == 0 && y % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}