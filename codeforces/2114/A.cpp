#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    for (int a = 0; a <= 100; a++) {
        for (int b = a; b <= 100; b++) {
            if ((a + b) * (a + b) == n) {
                cout << a << " " << b << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}