#include<bits/stdc++.h>
using namespace std;

void man()
{
    long long l,r;
    cin>>l>>r;
    cout<<r-l+1<<'\n';
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