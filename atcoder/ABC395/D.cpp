// Date: 2025-03-01
// Time: 20:16:34

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int>home(n+1);
    vector<int>p(n+1),pos(n+1);
    for(int i=1;i<=n;i++)
        home[i]=p[i]=pos[i]=i;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int a,b;
            cin>>a>>b;
            home[a]=pos[b];
            //我们还得知道 哪个pi 等于 b...
            //这样好像也不对，纯乱写了一坨。。。
        }else if(op==2){
            int a,b;
            cin>>a>>b;
            //p[30]不就是8吗？
            swap(p[pos[a]],p[pos[b]]);
            //p[rev[b]] p[xx]=b
            swap(pos[a],pos[b]);
            // cerr<<p[a]<<" "<<p[b]<<'\n';
            // rev[p[p[a]]]=p[a],p[p[b]]=p[b];
        }else{
            int a;
            cin>>a;
            cout<<p[home[a]]<<'\n';
        }
        // for(int i=1;i<=n;i++)
        //     cerr<<p[i]<<" \n"[i==n];
        // for(int i=1;i<=n;i++)
        //     cerr<<rev[i]<<" \n"[i==n];
    }
    // cerr<<rev[7]<<" "<<rev[8]<<" "<<rev[30]<<'\n';
}

//刚开始 8 和 30换
//然后   7 和 30换
//8的home本来是 30，然后我们需要让他变成7

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}