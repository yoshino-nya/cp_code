#include<cstdio>
#define N (200010)  // 定义最大数据范围(节点数+操作数)

using namespace std;

// 快速读入整数优化函数
inline int read(int &data) {
    data = 0;
    char ch = 0;
    while (ch < '0' || ch > '9') ch = getchar();  // 跳过非数字字符
    while (ch >= '0' && ch <= '9') 
        data = data * 10 + ch - '0', ch = getchar();  // 逐位构造整数
    return data;
}

// 动态开点线段树节点结构体
struct xds {
    int l, r;    // 当前节点管理的值域区间[l, r]
    int sum;     // 区间内元素总个数
    int ch[2];   // 左右子节点在t数组中的下标(0:左,1:右)
} t[N << 5];     // 总空间复杂度O(n log n)，N<<5保证足够空间

int n, m, ind;          // ind: 动态开点计数器
int T[N];               // T[i]: 第i个集合对应的线段树根节点
int fa[N];              // fa[i]: 并查集父节点数组
int ans[N];             // ans[x]: 值x对应的原始节点编号

// 并查集查找(带路径压缩)
int ask(int x) {
    return (fa[x] == x) ? x : fa[x] = ask(fa[x]);
}

// 在值域[l,r]的线段树中插入值p，返回新根节点
int insert(int p, int l, int r) {
    int rt = ++ind;                // 动态开点
    t[rt].l = l, t[rt].r = r;      // 设置区间范围
    t[rt].sum = 1;                 // 当前区间元素数量初始化为1
    if (l == r) return rt;         // 叶子节点直接返回
    
    int mid = (l + r) >> 1;
    // 递归插入子节点
    if (p > mid) t[rt].ch[1] = insert(p, mid + 1, r);  // 插入右子树
    else t[rt].ch[0] = insert(p, l, mid);              // 插入左子树
    return rt;
}

// 合并两棵线段树，返回合并后的根节点
int unite(int L, int R, int l, int r) {
    // 如果两个节点都为空，返回空
    if (!L && !R) return 0;
    // 如果其中一个为空，直接返回另一个(优化空间)
    if (!L) return R;
    if (!R) return L;
    
    // 创建新节点(保留合并前的树结构，实现持久化)
    int rt = ++ind;
    t[rt].l = l, t[rt].r = r;
    t[rt].sum = t[L].sum + t[R].sum;  // 合并元素数量
    
    int mid = (l + r) >> 1;
    // 递归合并左右子树
    t[rt].ch[0] = unite(t[L].ch[0], t[R].ch[0], l, mid);     // 合并左区间
    t[rt].ch[1] = unite(t[L].ch[1], t[R].ch[1], mid + 1, r); // 合并右区间
    return rt;
}

// 在线段树x中查询第k小的元素值
int query(int x, int k) {
    if (t[x].sum < k) return -1;  // 元素不足时返回-1
    
    // 到达叶子节点，返回该值
    if (t[x].l == t[x].r) return ans[t[x].l];  // 通过ans数组映射回原始节点
    
    // 左子树元素足够则查左子树，否则查右子树并减去左子树大小
    if (t[t[x].ch[0]].sum >= k)
        return query(t[x].ch[0], k);
    else
        return query(t[x].ch[1], k - t[t[x].ch[0]].sum);
}

int main() {
    read(n), read(m);  // 读取节点数和初始合并操作数
    
    // 初始化：每个节点独立为一个集合
    for (int i = 1; i <= n; i++) {
        fa[i] = i;      // 并查集初始化
        int x;
        read(x);        // 读取该节点的值x
        T[i] = insert(x, 1, n);  // 创建只含x的线段树
        ans[x] = i;     // 记录值x对应的原始节点编号
    }
    
    // 处理初始合并操作
    for (int i = 1; i <= m; i++) {
        int x, y;
        read(x), read(y);
        int p = ask(x), q = ask(y);  // 找到两个集合的根
        
        if (p != q) {
            fa[p] = q;  // 合并集合
            T[q] = unite(T[p], T[q], 1, n);  // 合并对应线段树
        }
    }
    
    int Q;
    read(Q);  // 查询操作数量
    while (Q--) {
        int x, y;
        char c;
        c = getchar();
        while (c != 'B' && c != 'Q') c = getchar();  // 跳过无效字符
        
        read(x), read(y);
        if (c == 'Q') {
            // 查询操作：在x所在集合中找第y小的元素
            int root = T[ask(x)];  // 获取集合对应的线段树根
            printf("%d\n", query(root, y));
        } else {
            // 合并操作：类似初始合并
            int p = ask(x), q = ask(y);
            if (p != q) {
                fa[p] = q;
                T[q] = unite(T[p], T[q], 1, n);
            }
        }
    }
    return 0;
}