// Date: 2025-03-11
// Time: 22:40:02

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<sum-(n-1)<<'\n';
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