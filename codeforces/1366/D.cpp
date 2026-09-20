// lcm(d1, d2) | a
// gcd(d1, d2) = 1
// d1 * d2 | a
// 
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 10000000;
vector<int> primes;
int minp[N + 1];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(!minp[i]){
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes){
            if(i * p > N) break;
            minp[i * p] = p;
            if(i % p == 0) break;
        }
    }
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<array<int, 2>> ans(n + 1, {-1, -1});
    for(int i = 1; i <= n; i++){
        int d = 1, p = minp[a[i]];
        while(a[i] % p == 0){
            a[i] /= p, d *= p;
        }
        if(a[i] != 1)
            ans[i] = {a[i], d};
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i][0] << " \n" [i == n];
    for(int i = 1; i <= n; i++)
        cout << ans[i][1] << " \n" [i == n];
    return 0;
}