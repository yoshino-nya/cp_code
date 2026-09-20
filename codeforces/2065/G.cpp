#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5;
bitset<N + 1> is;
std::vector<int> primes;
// 记一下最小质因子
vector<int> minp(N + 1);

void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    int sum = 0;
    vector<int> cnt(n + 1);
    // auto sqrtI = [&](int x) {
    //     int y = (int)sqrt(x);
    //     return y * y == x ? y : 0;
    // };
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        int x = a[i - 1];
        // cin >> x;
        cnt[x]++;
        if (!is[x]) {
            // 如果是一个质数，那么只能和其他的质数，除了它本身
            sum++;
            ans += sum - cnt[x];
            // 还得看一下 x*x
            if (1LL * x * x <= n)
                ans += cnt[x * x];
        } else {
            // 否则判一下最小质因子
            if (!is[x / minp[x]]) {
                // cerr << x << " " << minp[x] << '\n';
                // 如果只有两个质因子 那么答案加上这两个的数量
                // 当然它自己和自己也是可以的
                ans += cnt[minp[x]] + cnt[x];
                if (1LL * minp[x] * minp[x] != x)
                    ans += cnt[x / minp[x]];
            }
            // 2 3 ,6 ,2 7
        }
    }
    cout << ans << '\n';
}
/*
6
5 4 6 6 2 3
这为什么会是8呢？
5 2,5 3,2 3,2 4
6 2,6 3. 偶没有判 质数可能和倍数
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= N; i++) {
        if (!is[i]) {
            minp[i] = i;
            primes.push_back(i);
            // cerr << i << '\n';
            if (1LL * i * i > N)
                continue;
            for (int j = i * i; j <= N; j += i) {
                is[j] = true, minp[j] = i;
            }
        }
    }
    // cout << primes.size() << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}