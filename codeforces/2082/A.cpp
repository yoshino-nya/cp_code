// Date: 2025-03-15
// Time: 22:57:44

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(count(s[i].begin(),s[i].end(),'1')&1) ans++;
    }
    int res=0;
    for(int j=0;j<m;j++){
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i][j]=='1') x^=1;
        }
        res+=x;
    }
    cout<<max(ans,res)<<'\n';
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