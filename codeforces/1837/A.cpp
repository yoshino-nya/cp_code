// Date: 2025-03-25
// Time: 19:05:59
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int x,k;
    cin>>x>>k;
    if(x%k==0){
        cout<<"2\n";
        cout<<"1 "<<x-1<<'\n';
    }else cout<<"1\n"<<x<<'\n';
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