// Date: 2025-02-28
// Time: 22:40:23

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long sum=0;
    priority_queue<int>q;
    for(int i=n;i>=1;i--)
        q.push(i);
    auto check=[](long long x){
        long long y=(long long)sqrt(x);
        return x!=y*y;
    };
    vector<int>ans;
    while(!q.empty()){
        if(check(sum+q.top())){
            ans.push_back(q.top());
            sum+=q.top();
            q.pop();
        }else{
            int x=q.top();
            q.pop();
            if(q.empty()){
                cout<<"-1\n";
                return;
            }
            ans.push_back(q.top());
            sum+=q.top();
            q.pop();
            q.push(x);
            
        }
    }
    for(auto x:ans)
        cout<<x<<" ";
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
        solve();
    return 0;
}