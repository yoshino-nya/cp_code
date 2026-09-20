#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    multiset<int> sx, sy;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sx.insert(x[i]);
        sy.insert(y[i]);
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    ll ans = ll(1e18);
    for (int i = 0; i < n; i++) {
        sx.erase(sx.find(x[i]));
        sy.erase(sy.find(y[i]));
        // ans = min(ans, static_cast<ll>(*sx.rbegin() - *sx.begin() + 1) * (*sy.rbegin() - *sy.begin() + 1));
        ll a = *sx.rbegin() - *sx.begin() + 1;
        ll b = *sy.rbegin() - *sy.begin() + 1;
        if (a > b) swap(a, b);
        if (a * b < n) {
            ans = min(ans, a * (b + 1));
        }else {
            ans = min(ans, a * b);
        }
        sx.insert(x[i]);
        sy.insert(y[i]);
    }
    cout << ans << '\n';
}

int main() {
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}