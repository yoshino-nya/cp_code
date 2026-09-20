// Date: 2025-03-22
// Time: 20:03:26
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    vector<int>cnt(14);
    for(int i=1;i<=7;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    sort(cnt.begin(),cnt.end(),greater<>());
    if(cnt[0]>=3&&cnt[1]>=2) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}