/*
a % b != a a > b
a % b < b
a > b > c
a > b && a % b != 0
n * (n - 1) / 2 - 整除的对的数量

n / 1 + n / 2 + n / 3 ... 
值的数量是有限的 sqrt(n) 范围

n / l <= n / r
r <= n / (n / l)
*/
#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
long long ksm(long long a, long long b)
{
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
long long inv(long long x) {return ksm(x, mod - 2);}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long N;
    cin >> N;
    long long ans = N % mod;
    ans = ans * (ans + 1) % mod * inv(2) % mod;
    for(long long L = 1, R; L <= N; L = R + 1){
        R = N / (N / L);
        int len = (R - L + 1) % mod;
        int val = (N / L) % mod;
        ans -= 1LL * len * val % mod;
        ans %= mod;
    }
    cout << (ans + mod) % mod << '\n';
    return 0;
}