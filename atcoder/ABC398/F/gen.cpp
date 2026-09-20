#include <bits/stdc++.h>
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
    int n = rand_integer(1, 50);
    string s;
    for (int i = 0; i < n; i++)
        s.push_back('A' + rand_integer(0, 25));
    cout << s << '\n';
    return 0;
}