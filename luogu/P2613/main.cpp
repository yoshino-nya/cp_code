#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 19260817;
int phi;
int ksm(int a, int b)
{
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return ksm(x, phi - 1);
}
void solve()
{
    // 求 a * b ^ -1
    auto read = [&](){
        string s; cin >> s;
        LL res = 0;
        for(auto c : s)
            res = (res * 10 + c - '0') % mod;
        return res;
    };
    int a = read(), b = read();
    if(gcd(b, mod) != 1)
        cout << "Angry!\n";
    else
        cout << 1LL * a * inv(b) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x = mod;
    phi = mod;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            phi = phi / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) phi = phi / x * (x - 1);
    // cerr << phi << '\n';
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}