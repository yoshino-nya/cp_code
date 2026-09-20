// Date: 2025-03-10
// Time: 22:46:17

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    //如果选了一个因子 那么？
    //3？
    if(sum==n*x) cout<<"YES\n";
    else cout<<"NO\n";
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