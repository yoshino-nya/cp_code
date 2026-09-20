#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 40000;
int phi[N + 1], minp[N + 1];
void solve()
{
    int n; cin >> n;
    if(n == 1) cout << "0\n";
    else
        cout << accumulate(phi + 2, phi + n, 0LL) * 2 + 3 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<int> primes;
    for(int i = 2; i <= N; i++){
        if(!minp[i]){
            primes.push_back(i);
            minp[i] = i;
            phi[i] = i - 1;
        }
        for(int p : primes){
            if(i * p > N) break;
            minp[i * p] = p;
            if(i % p == 0){
                phi[p * i] = phi[i] * p;
                break;
            }
            else
                phi[p * i] = phi[i] * (p - 1);
        }
    }

    // int t; cin >> t; while(t--)
    {solve();} return 0;
}