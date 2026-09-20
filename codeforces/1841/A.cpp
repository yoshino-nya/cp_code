/*
不能走的人赢
n=1 Bob
所以n=2 3 Bob
n=4? Bob (2,1,1) (2,2) (4)
n=5? Alice
n=6? Alice

*/
// Date: 2025-03-19
// Time: 08:14:52

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin>>n;
    if(n<=4) cout<<"Bob\n";
    else cout<<"Alice\n";
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