// Date: 2025-03-10
// Time: 22:58:23

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n,k;
    cin>>n>>k;
    //k为奇数？
    //全为 n ，除了最后一个
    //k为偶数？
    //第一次全部去n-1 ，然后n-1去n
    

    //2 2?
    //2 1
    if(k&1){
        for(int i=1;i<=n-1;i++){
            cout<<n<<' ';
        }
        cout<<n-1<<'\n';
    }else{
        for(int i=1;i<n-1;i++)
            cout<<n-1<<' ';
        cout<<n<<" "<<n-1<<'\n';
    }
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