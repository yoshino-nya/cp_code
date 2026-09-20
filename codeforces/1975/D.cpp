// 感觉只能一个子树一个子树的走。。。
// 如果蓝色的不在根节点或与根相连
// 那么我们肯定让红色的先走它在的子树
// 然后它自己走到深度为1的点就好了 否则它需要走到根节点去
// 如果在根节点 那么需要额外花费两个费用
// 遍历一个子树必然会把这个子树的每条边都走两次 除了最后去的一些边。。
// 。。。。好像很不好讨论的。。。。

// 好像还真是什么很神奇的结论。。。
// 太牛，也是直接看了题解。。
// 遍历一颗树 如果最后要回到根节点 那么最小的走的路程就是每条边都走两次
// 但是如果最后不回来呢？实际上就是减少了最后一个点到根节点的距离
// 所以如果最后不回来，那我们希望它最后一个去的点距离根节点最远

// 所以我们希望a b 尽可能快的相遇。。
// 无法相遇也没关系。因为那就相当于红色比蓝色多一步了，那它显然可以去提前把蓝色要走的路给染色好
// 如果可以相遇 那就正好一起走就直接染成蓝色
// 所以其实就是希望蓝色的点尽可能快地走到被染成红色的点

// 所以最后的答案就是，2(n-1)-d
// d 为 a b 相遇的点到最远的点的距离
// 有没有可能移动初始的点使得d 更大呢？没有
// 因为你一次移动最多就使得d+1 这跟不移动 没啥区别

// Date: 2025-03-17
// Time: 16:25:11

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dep(n + 1), f(n + 1);
    auto dfs = [&](auto&& self, int u, int pre) -> void {
        for (auto v : adj[u]) {
            if (v == pre)
                continue;
            f[v] = u;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, a, 0);
    int st = b, ans = 2 * (n - 1);
    for (int i = 1; i <= dep[b] / 2; i++, ans++)
        st = f[st];
    if(dep[b]&1) st=f[st],ans++;
    dep[st] = 0;
    dfs(dfs, st, 0);
    cout << ans - *max_element(dep.begin() + 1, dep.end()) << '\n';
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