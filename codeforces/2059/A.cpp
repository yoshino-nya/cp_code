#include<bits/stdc++.h>
using namespace std;

void man()
{
    int n;
    cin>>n;
    set<int>a,b;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.insert(x);
    }
    if(a.size()*b.size()>=3)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        man();
    return 0;
}