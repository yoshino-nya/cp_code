#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int get_phi(int x)
{
    int res = x;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            res = res / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}
int ksm(int a, int b, int mod)
{
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int a, m; cin >> a >> m;
    int phi = get_phi(m);
    bool ok = false;
    auto read = [&](){
        LL res = 0;
        string s; cin >> s;
        for(auto c : s){
            res = (res * 10 + c - '0');
            if(res >= phi){
                ok = true;
                res %= phi;
            }
        }
        return res;
    };
    int b = read();
    // cerr << b << " " << phi << '\n';
    if(gcd(a, m) != 1 && ok) b += phi;
    cout << ksm(a, b, m) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}