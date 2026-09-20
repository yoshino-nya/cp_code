// Date: 2025-03-02
// Time: 01:44:01

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+1;
int a[N<<1], pre[N<<1];

void solve()
{
    // n为奇数时
    // a[n+1]=a[n+2]
    // a[n+3]=a[n+4]
    // a[2m]=a[2m+1] 设 p = xor[1,n]
    // 那么如果 m&1 ,res=p
    // 可以弄到 m<=2*n
    int n;
    long long l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
    if (n % 2 == 0) {
        n++;
        a[n] = pre[n >> 1];
        pre[n] = pre[n - 1] ^ a[n];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        a[i] = pre[i >> 1];
        pre[i] = pre[i - 1] ^ a[i];
    }
    // 刚刚还在想 不是求和吗。。。
    // 原来在这个题里 l=r。。。才发现啊··
    //  n]
    auto query = [&](auto self, long long i) -> int {
        if (i <= 2 * n)
            return a[i];
        if (i >> 1 & 1)
            return pre[n];
        return pre[n] ^ self(self, i / 2);
    };
    cout << query(query, l) << '\n';
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
// 我们现在可以知道什么呢？
// 新加的数字里面，第偶数个后面一个肯定是和前一个是一样的，
// 因为若 m&1, m/2=(m+1)/2
// 也就是说后面的数字，必然两个两个的出现，
// 偶数个1抑或一起相当于没有抑或
// 所以这些段的值必然都为0
//
// 然而这个作用不大啊
// 0 1 0 1
// 1 , 1 1,0 0,1 1,0 0,1 1,1 1,

// 0 会让它们继续复制前面的东西
// 所以好像其实也没太多规律

// 应该还是挺难的，这会才想了十分钟，明天再想一会。

//
// int n,l,r;
// cin>>n>>l>>r;
// for(int i=1;i<=n;i++)
//     cin>>a[i],pre[i]=pre[i-1]^a[i];
// cout<<'\n';
// for(int i=n+1;i<=100;i++){
//     a[i]=pre[i>>1];
//     pre[i]=pre[i-1]^a[i];
//     cout<<a[i]<<" ";
//     if((i-n)%n==0) cout<<'\n';
// }

// 似乎看不出来什么规律
//[1,0,1,1,1]
//[0,0,1,1,0,0]
//[0,0,0,0,1,1,0,0,0,0]
//[0,0,0,0,0,0,0,0,1,1,0,0,0,0,0]