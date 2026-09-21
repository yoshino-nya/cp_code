/*
date: 2026-09-21 23:12:09
path: ~/Projects/cp_code/codeforces/2266/F.cpp
*/

#include <algorithm>
#include <cstdio>
#include <map>

void solve()
{
    int n; scanf("%d", &n);
    std::map<int, int> mp;
    int ans = 0;
    long long cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        mp[x] = y;
        ans = std::max(ans, x);
        cnt += y;
    }
    long long cur = cnt;
    bool ok = false;
    for(int i = 1; ;i++) {
        if(mp.contains(i) && )
    }
}
int main()
{
    int t; scanf("%d", &t);
    while(t--) solve();
}

/*
生成一个 x 需要前面所有数字都 -1

转化的 x >= 2 || 转化1个 本来有至少一个

那么要变成 x+2，转的 x+1 >= 2 || 转化一个 本来有一个
也就是说转的 x>=4 || 转化两个 x||

次数应该不会很多，试一下

不行啊我擦，可以变成0的。。。

假如知道答案是多少

那么前面的数字每个都得有一个
核心还是看0够不够吧

一个个的看得了。。。
检查每个数字是否可以达成，那我为了去确保尽量能多用
肯定会把 比这个数字多的 全变成0
那我就看达成每个地方的时候 多了多少个0
如果用完了 那后面的 肯定变不成了

也不是吧，如果转化来的 x 多于 1了，那么0一定有多的，

啊 不对
有的话我肯定要留一个
不然你答案肯定更小啊

但是我们希望每个数字至少有一个
不行 这太麻烦了
*/