// Date: 2025-03-11
// Time: 22:35:39

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    array<int, 4>a;
    for(int i=0;i<4;i++)
        cin>>a[i],a[i]=abs(a[i]);
    sort(a.begin(),a.end());
    if(a[0]==a[3])
        cout<<"YES\n";
    else
        cout<<"NO\n";
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