/*
10 6
10 8 20 14 3 8 6 4 16 11
算当前的前面 选1个数 选2个数 选k个数字的答案...
它应该只会在一个区间里生效
我们遇到更好的数字 就把比它大的最小的数字的贡献全都改一下
比如10 它的贡献的区间只有 [1,1] 因为只有一个数字
8它的贡献是[1,2] 改成 [8,8]
实际上就是进行一个区间减的操作
好像就是看是第几大的吧

怎么查第几大呢？还要插入
这个应该也得要一个线段树的 不对 这个不用。。树状数组就行
没事 离散化一下就行
*/
// Date: 2025-03-25
// Time: 20:10:40
#include <bits/stdc++.h>
using namespace std;

struct Fenwick
{
    vector<int> b;
    Fenwick(int n)
    {
        b = vector<int>(n + 1);
    }
    int lowbit(int x) { return (x) & (-x); }
    void add(int i, int x)
    {
        while (i && i < b.size())
        {
            b[i] += x;
            i += lowbit(i);
        }
    }
    int ask(int i)
    {
        int res = 0;
        while (i)
        {
            res += b[i];
            i -= lowbit(i);
        }
        return res;
    }
};
void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i - 1] = a[i];
    Fenwick C(n + 1);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    reverse(b.begin(), b.end());
    // for (auto x : b)
    //     cout << x << " ";
    // cout << '\n';
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(a[i]);
        int last = a[i];
        {
            auto it = st.upper_bound(a[i]);
            if (it != st.end())
                last = *prev(it);
        }
        int idx = lower_bound(b.begin(), b.end(), a[i], [](int x, int y)
                              { return x > y; }) -
                  b.end() + 1;
        C.add(idx, 1);
        int order = C.ask(idx - 1) + 1; // 查询它是第几大的？ 不对 好像是查第几小啊 就是查第几小吧。。。
        /* 如果把它删掉 那么b里面有些需要多加一些
        还是不太对啊。应该要可以休息了。。
         */
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