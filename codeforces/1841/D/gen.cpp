#include <iostream>
#include <random>
using namespace std;
using ll = long long;

mt19937_64 rng(time(NULL));
ll rand_integer(ll l, ll r)
{
    uniform_int_distribution<ll> dis(l, r);
    return dis(rng);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "1\n";
    int n = rand_integer(1, 10);
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int l = rand_integer(0, 10), r = rand_integer(l, l + 10);
        cout << l << " " << r << " \n";
    }
    return 0;
}