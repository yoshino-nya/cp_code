// Date: 2025-03-10
// Time: 19:21:33

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin>>n;
    vector<array<int, 2>>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end(),[](array<int,2>x,array<int,2>y){
        return x[0]+x[1]<y[0]+y[1];
    });
    for(int i=0;i<n;i++)
        cout<<a[i][0]<<" "<<a[i][1]<<" \n"[i+1==n];
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