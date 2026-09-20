// Date: 2025-03-15
// Time: 20:00:37

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    double x;
    cin>>x;
    if(x>=38.0){
        cout<<"1\n";
    }else if(x>=37.5){
        cout<<"2\n";
    }else{
        cout<<"3\n";
    }
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