#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;                   // 节点数量
int cl[100005];          // 每个点的颜色编号
int rt[100005];          // 每个节点对应的线段树根节点编号
ll anss[100005];         // 最终答案：每个节点子树中颜色出现次数最多的颜色编号之和

vector<int> g[100005];   // 树的邻接表

// 线段树节点结构体
struct tree {
	int l, r;      // 左右儿子的编号（在数组 tr 中的下标）
	int sum;       // 当前颜色出现的次数
	int val;       // 当前节点代表的颜色编号
	ll ans;        // 子树中出现次数最多的颜色编号的“编号之和”
} tr[5000050];     // 动态开点最多开到 5e6 个点

int cnt = 0;       // 当前线段树的总节点数

#define lson tr[now].l
#define rson tr[now].r

// 向上传递信息
void push_up(int now) {
	if (tr[lson].sum > tr[rson].sum) {
		// 左子树颜色更频繁
		tr[now] = tr[lson];
	} else if (tr[rson].sum > tr[lson].sum) {
		// 右子树颜色更频繁
		tr[now] = tr[rson];
	} else {
		// 出现频率相同，合并颜色编号
		tr[now].sum = tr[lson].sum;
		tr[now].val = tr[lson].val; // 实际不重要
		tr[now].ans = tr[lson].ans + tr[rson].ans;
	}
}

// 单点更新：颜色 pos 的出现次数 +v
void update(int &now, int l, int r, int pos, int v) {
	if (!now) now = ++cnt; // 如果这个节点未创建，则分配新节点
	if (l == r) {
		// 到达颜色叶子节点
		tr[now].val = l;
		tr[now].sum += v;
		tr[now].ans = l;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(lson, l, mid, pos, v); // 递归左子树
	else update(rson, mid + 1, r, pos, v);        // 递归右子树
	push_up(now); // 更新当前节点信息
}

// 合并两棵线段树（动态开点线段树）
// 返回合并后的根节点编号
int merge(int a, int b, int l, int r) {
	if (!a) return b;
	if (!b) return a;
	if (l == r) {
		tr[a].sum += tr[b].sum;
		tr[a].ans = tr[a].val = l;
		return a;
	}
	int mid = (l + r) >> 1;
	tr[a].l = merge(tr[a].l, tr[b].l, l, mid);         // 合并左子树
	tr[a].r = merge(tr[a].r, tr[b].r, mid + 1, r);     // 合并右子树
	push_up(a);                                        // 更新根节点信息
	return a;
}

// 树的 DFS 遍历，顺便合并线段树
void dfs(int now, int f) {
	for (int i = 0; i < g[now].size(); i++) {
		if (g[now][i] == f) continue;      // 跳过父节点
		dfs(g[now][i], now);              // 先处理子节点
		rt[now] = merge(rt[now], rt[g[now][i]], 1, 100000); // 合并子树的颜色统计
	}
	update(rt[now], 1, 100000, cl[now], 1); // 把当前点的颜色也加入进去
	anss[now] = tr[rt[now]].ans;           // 当前节点的答案就是众数的“颜色编号和”
}

int main() {
	scanf("%d", &n); // 输入节点数
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cl[i]); // 每个点的颜色编号
		rt[i] = i;           // 初始每个点是独立的线段树根
		cnt++;               // 分配线段树节点编号
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v); // 读树边
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0); // 从根节点开始 DFS
	for (int i = 1; i <= n; i++) printf("%lld ", anss[i]); // 输出答案
}
