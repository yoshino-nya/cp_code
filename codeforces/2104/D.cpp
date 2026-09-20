#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int lmt = int(6e6);
bitset<lmt+1>is;
vector<int>primes(1);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i] - primes[i];
        if(sum < 0){
            cout << n - i + 1 << '\n';
            return;
        }
    }
    cout << "0\n";
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    for(int i=2;i<=lmt;i++){
        if(is[i]) continue;
        primes.push_back(i);
        if(ll(i)*i>lmt) continue;
        for(int j=i*i;j<=lmt;j+=i)
            is[j]=1;
    }
    // cout<<primes.size()<<'\n';
    // for(int i=0;i<100;i++)
    //     cerr<<primes[i]<<" ";
    int t = 1; 
    cin >> t;
    while(t--)
        solve();
    return 0;
}