// Date: 2025-03-21
// Time: 09:11:04

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv = ksm(2, mod - 2);
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<ll> f(n);
    reverse(s.begin(), s.end());
    if (s[0] == '1')
        f[0] = inv;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1')
            f[i] = (1 - f[i - 1]) * inv % mod + f[i - 1];
        else
            f[i] = inv * f[i - 1] % mod;
        f[i] = (f[i] + mod) % mod;
    }
    cout << (n - 1 + f[n - 2]) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}