#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>a(7);
    for(int i=0;i<7;i++){
        cin>>a[i];
    }
    for(int i=0;i<7;i++){
        if(a[i]==4||a[i]==7){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}