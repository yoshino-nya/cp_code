// Date: 2025-04-03
// Time: 22:41:37
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    vector<ll> pre(n + 1), nxt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    auto ask = [&](ll i)
    {
        return pre[n] * (i / n) + pre[i % n];
    };
    auto calc = [&](ll l, ll r)
    {
        return ask(r) - ask(l - 1);
    };
    
    ll lo=0,hi=1LL*n*k+1;
    while(lo<hi-1){
        ll mid=(lo+hi)>>1;
        if(calc(mid,1LL*n*k)>=x)
            lo=mid;
        else hi=mid;
    }
    cout<<lo<<'\n';
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