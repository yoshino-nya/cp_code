#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6);
int minp[N + 1];

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    {int g = gcd(x, y); x /= g, y /= g;}
    vector<int> px, py;
    while (x != 1) {
        int p = minp[x];
        if(p > k){
            cout << "-1\n";
            return;
        }
        while (x % p == 0){
            x /= p;
            px.push_back(p);
        }
    }
    while (y != 1) {
        int p = minp[y];
        if(p > k){
            cout << "-1\n";
            return;
        }
        while (y % p == 0){
            y /= p;
            py.push_back(p);
        }
    }
    auto calc = [&](vector<int> vec) {
        int res = vec.size();
        sort(vec.begin(), vec.end());
        do{
            ll x = 1;
            int ans = 1;
            for(auto p : vec){
                if(x * p <= k)
                    x *= p;
                else{
                    x = p;
                    ans++;
                }
            }
            res = min(res, ans);
        }while(next_permutation(vec.begin(), vec.end()));
        return res;
    };
    cout << calc(px) + calc(py) << '\n';
}

int main() {
    for (int i = 2; i <= N; i++) {
        if (minp[i]) continue;
        minp[i] = i;
        if (ll(i) * i > N) continue;
        for (int j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}