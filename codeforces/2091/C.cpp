/*
1 3 5 2 4
4 1 3 5 2
2 4 1 3 5

1 3 2 4
*/
// Date: 2025-03-26
// Time: 20:32:59
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"-1\n";
        return;
    }
    for(int i=1;i<=n;i+=2)
        cout<<i<<" ";
    for(int i=2;i<=n;i+=2)
        cout<<i<<" ";
    cout<<'\n';
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