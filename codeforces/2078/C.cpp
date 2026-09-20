// Date: 2025-03-10
// Time: 23:07:49

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    //+b0 -b1
    int n;
    cin >> n;
    vector<int> b(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) {
        cin >> b[i];
    }
    sort(b.begin() + 1, b.end());

    // set<int> st1, st2;
    // ll s1 = 0, s2 = 0;
    // for (int i = 1; i <= n; i++)
    //     st1.insert(b[i]), s1 += b[i];
    // for (int i = n + 1; i <= n * 2; i++)
    //     st2.insert(b[i]), s2 += b[i];

    //如果说大的n 个 减去小的 n个
    //正好等于了某一个值
    
    //- + - + -
    //选一个很大的数字，然后减了之后正好等于an?可行吗

    //4
    //1 2 3 4
    //6-1+2-3
    ll s=b[2*n];
    //s-x=a[2n]
    for(int i=1;i<2*n;i++){
        if(i&1) s+=b[i];
        else s-=b[i];
    }
    cout<<b[2*n]<<" "<<s<<' ';
    for(int i=1;i<2*n;i++)
        cout<<b[i]<<" \n"[i+1==2*n];
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